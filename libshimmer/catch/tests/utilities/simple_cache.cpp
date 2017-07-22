#include "catch.hpp"
#include "simple_cache.hpp"
#include <memory>
#include <string>

using namespace std;
using namespace shimmer;

TEST_CASE ( "Check if simple cache is able to store integers." )
{
    typedef shared_ptr<cache<string, int>> icache_t;
    typedef simple_cache<string, int> simple_cache_t;

    icache_t icache = make_shared<simple_cache_t> ( "catch_integers" );

    icache->set ( "a",  1 );
    icache->set ( "b",  2 );
    icache->set ( "d",  4 );

    CHECK ( icache->exists ( "a" ) == true );
    CHECK ( icache->exists ( "b" ) == true );
    CHECK ( icache->exists ( "d" ) == true );
    CHECK ( icache->exists ( "c" ) == false );
    CHECK ( icache->exists ( "e" ) == false );

    CHECK ( icache->get ( "a" ) == 1 );
    CHECK ( icache->get ( "b" ) == 2 );
    CHECK ( icache->get ( "d" ) == 4 );
    CHECK ( icache->get ( "c" ) == 0 );
    CHECK ( icache->get ( "e" ) == 0 );

    icache->set ( "a",  11 );
    icache->set ( "b",  22 );
    icache->set ( "d",  44 );

    CHECK ( icache->exists ( "a" ) == true );
    CHECK ( icache->exists ( "b" ) == true );
    CHECK ( icache->exists ( "d" ) == true );
    CHECK ( icache->exists ( "c" ) == false );
    CHECK ( icache->exists ( "e" ) == false );

    CHECK ( icache->get ( "a" ) == 11 );
    CHECK ( icache->get ( "b" ) == 22 );
    CHECK ( icache->get ( "d" ) == 44 );
    CHECK ( icache->get ( "c" ) == 0 );
    CHECK ( icache->get ( "e" ) == 0 );
}

TEST_CASE ( "Check if simple cache is able to store strings." )
{
    typedef shared_ptr<cache<string, string>> scache_t;
    typedef simple_cache<string, string> simple_cache_t;

    scache_t scache = make_shared<simple_cache_t> ( "catch_strings" );

    scache->set ( "a",  "string a" );
    scache->set ( "b",  "string b" );
    scache->set ( "d",  "string d" );

    CHECK ( scache->exists ( "a" ) == true );
    CHECK ( scache->exists ( "b" ) == true );
    CHECK ( scache->exists ( "d" ) == true );
    CHECK ( scache->exists ( "c" ) == false );
    CHECK ( scache->exists ( "e" ) == false );

    CHECK ( scache->get ( "a" ) == "string a" );
    CHECK ( scache->get ( "b" ) == "string b" );
    CHECK ( scache->get ( "d" ) == "string d" );
    CHECK ( scache->get ( "c" ) == "" );
    CHECK ( scache->get ( "e" ) == "" );

    scache->set ( "a",  "STRING AA" );
    scache->set ( "b",  "STRING BB" );
    scache->set ( "d",  "STRING DD" );

    CHECK ( scache->exists ( "a" ) == true );
    CHECK ( scache->exists ( "b" ) == true );
    CHECK ( scache->exists ( "d" ) == true );
    CHECK ( scache->exists ( "c" ) == false );
    CHECK ( scache->exists ( "e" ) == false );

    CHECK ( scache->get ( "a" ) == "STRING AA" );
    CHECK ( scache->get ( "b" ) == "STRING BB" );
    CHECK ( scache->get ( "d" ) == "STRING DD" );
    CHECK ( scache->get ( "c" ) == "" );
    CHECK ( scache->get ( "e" ) == "" );
}

TEST_CASE ( "Check if simple cache is able to store shared_ptr strings." )
{
    typedef shared_ptr<cache<string, shared_ptr<string>>> scache_t;
    typedef simple_cache<string, shared_ptr<string>> simple_cache_t;

    scache_t scache = make_shared<simple_cache_t> ("catch_shared_strings");

    scache->set ( "a",  make_shared<string> ( "string a" ) );
    scache->set ( "b",  make_shared<string> ( "string b" ) );
    scache->set ( "d",  make_shared<string> ( "string d" ) );

    CHECK ( scache->exists ( "a" ) == true );
    CHECK ( scache->exists ( "b" ) == true );
    CHECK ( scache->exists ( "d" ) == true );
    CHECK ( scache->exists ( "c" ) == false );
    CHECK ( scache->exists ( "e" ) == false );

    CHECK ( *scache->get ( "a" ) == "string a" );
    CHECK ( *scache->get ( "b" ) == "string b" );
    CHECK ( *scache->get ( "d" ) == "string d" );
    CHECK ( scache->get ( "c" ) == nullptr );
    CHECK ( scache->get ( "e" ) == nullptr );

    scache->set ( "a",  make_shared<string> ( "STRING AA" ) );
    scache->set ( "b",  make_shared<string> ( "STRING BB" ) );
    scache->set ( "d",  make_shared<string> ( "STRING DD" ) );

    CHECK ( scache->exists ( "a" ) == true );
    CHECK ( scache->exists ( "b" ) == true );
    CHECK ( scache->exists ( "d" ) == true );
    CHECK ( scache->exists ( "c" ) == false );
    CHECK ( scache->exists ( "e" ) == false );

    CHECK ( *scache->get ( "a" ) == "STRING AA" );
    CHECK ( *scache->get ( "b" ) == "STRING BB" );
    CHECK ( *scache->get ( "d" ) == "STRING DD" );
    CHECK ( scache->get ( "c" ) == nullptr );
    CHECK ( scache->get ( "e" ) == nullptr );
}

TEST_CASE ( "Check if simple cache with specified default." )
{
    typedef shared_ptr<cache<string, string>> scache_t;
    typedef simple_cache<string, string> simple_cache_t;

    scache_t scache = make_shared<simple_cache_t> (
                          "catch_strings_default",
                          "empty" );

    scache->set ( "a",  "string a" );
    scache->set ( "b",  "string b" );
    scache->set ( "d",  "string d" );

    CHECK ( scache->exists ( "a" ) == true );
    CHECK ( scache->exists ( "b" ) == true );
    CHECK ( scache->exists ( "d" ) == true );
    CHECK ( scache->exists ( "c" ) == false );
    CHECK ( scache->exists ( "e" ) == false );

    CHECK ( scache->get ( "a" ) == "string a" );
    CHECK ( scache->get ( "b" ) == "string b" );
    CHECK ( scache->get ( "d" ) == "string d" );
    CHECK ( scache->get ( "c" ) == "empty" );
    CHECK ( scache->get ( "e" ) == "empty" );

    scache->set ( "a",  "STRING AA" );
    scache->set ( "b",  "STRING BB" );
    scache->set ( "d",  "STRING DD" );

    CHECK ( scache->exists ( "a" ) == true );
    CHECK ( scache->exists ( "b" ) == true );
    CHECK ( scache->exists ( "d" ) == true );
    CHECK ( scache->exists ( "c" ) == false );
    CHECK ( scache->exists ( "e" ) == false );

    CHECK ( scache->get ( "a" ) == "STRING AA" );
    CHECK ( scache->get ( "b" ) == "STRING BB" );
    CHECK ( scache->get ( "d" ) == "STRING DD" );
    CHECK ( scache->get ( "c" ) == "empty" );
    CHECK ( scache->get ( "e" ) == "empty" );
}
