// -*- C++ -*- Time-stamp: <99/02/02 18:29:54 ptr>

#ident "%Z% $Date$ $Revision$ $RCSfile$ %Q%"

#include <xxx/plock.h>
#include <cstring>
#include <ostream>

#ifdef WIN32
#include <iostream>
#endif

extern "C" {
#ifdef WIN32
  typedef unsigned long (__stdcall *entrance_type_C)( void * );
#else
  typedef void *(*entrance_type_C)( void * );
#endif
}

namespace __impl {

// #ifndef WIN32
using std::cerr;
using std::endl;
// #endif

Thread::Thread() :
#ifdef WIN32
    _id( (HANDLE)-1 ),
#else
    _id( -1 ),
#endif
    _entrance( 0 ),
    _param( 0 ),
    _param_sz( 0 )
{ }

Thread::Thread( Thread::entrance_type entrance, void *p, size_t psz ) :
    _entrance( entrance ),
    _param( 0 ),
    _param_sz( 0 )
{ _create( p, psz ); }

void Thread::launch( entrance_type entrance, void *p, size_t psz )
{
#ifdef WIN32
  if ( _id == (HANDLE)-1 ) {
#else
  if ( _id == -1 ) {
#endif
    _entrance = entrance;
    _create( p, psz );
  }
}

int Thread::join()
{
#ifdef WIN32
  unsigned long ret_code = 0;
  if ( _id != (HANDLE)-1 ) {
#else
  int ret_code = 0;
  if ( _id != -1 ) {
#endif
#ifdef _PTHREADS
    pthread_join( _id, (void **)(&ret_code) );
#endif
#ifdef _SOLARIS_THREADS
    thr_join( _id, 0, (void **)(&ret_code) );
#endif
#ifdef WIN32
    WaitForSingleObject( _id, -1 );
    GetExitCodeThread( _id, &ret_code );
    _id = (HANDLE)-1;
#endif
#ifndef WIN32
    _id = -1;
#endif
  }

  return ret_code;
}

void Thread::exit( int code )
{
#ifdef _PTHREADS
  pthread_exit( (void *)code );
#endif
#ifdef _SOLARIS_THREADS
  thr_exit( (void *)code );
#endif
#ifdef WIN32
  ExitThread( code );
#endif
}

void Thread::_create( void *p, size_t psz ) throw(runtime_error)
{
//	if ( _param_sz != 0 ) {
//	  delete [] _param;
//	}
  if ( psz > sizeof(void *) ) {
    _param = new char [psz];
#ifdef WIN32
    memcpy( _param, p, psz );
#else
    std::memcpy( _param, p, psz );
#endif
//	  MT_LOCK( _params_lock );
  } else {
    _param = p;	  
  }
  _param_sz = psz;

  int err;
#ifdef _PTHREADS
  err = pthread_create( &_id, 0, entrance_type_C(_call), this );
#endif
#ifdef _SOLARIS_THREADS
  err = thr_create( 0, 0, entrance_type_C(_call), this, 0, &_id );
#endif
#ifdef WIN32
  _id = CreateThread( 0, 0, entrance_type_C(_call), this, 0, &_thr_id );
  err = GetLastError();
#endif
  if ( err != 0 ) {
    if ( psz > sizeof( void *) ) {
      delete [] _param;
    }
    throw runtime_error( "Thread creation error" );
  }
}

void *Thread::_call( void *p )
{
  Thread *me = static_cast<Thread *>(p);
//	if ( me->_param_sz != 0 ) {
//	}
  int ret;

#ifdef WIN32
  set_unexpected( unexpected );
  set_terminate( terminate );
#else
  std::set_unexpected( unexpected );
  std::set_terminate( terminate );
#endif
	
  try {
    ret = me->_entrance( me->_param );
	  
    if ( me->_param_sz > sizeof(void *) ) {
      delete [] me->_param;
      me->_param_sz = 0;
      me->_param = 0;
    }
  }
  catch ( std::exception& e ) {
    cerr << e.what() << endl;
    ret = -1;
  }
  catch ( ... ) {
    cerr << "Oh, oh, say baby Sally. Dick and Jane launch." << endl;
    ret = -1;
  }
#if defined( __SUNPRO_CC ) && defined( __i386 )
  Thread::exit( ret );
#endif
  return (void *)ret;
}

void Thread::unexpected()
{
  cerr << "\nUnexpected exception" << endl;
  Thread::exit( -1 );
}

void Thread::terminate()
{
  cerr << "\nTerminated" << endl;
  Thread::exit( -2 );
}

} // namespace __impl