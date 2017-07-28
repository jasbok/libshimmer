#include "simple_cache.hpp"

#include "catch/catch.hpp"
#include "spdlog/spdlog.h"

#include <memory>
#include <string>

using namespace std;
using namespace shimmer;

TEST_CASE ( "Check if simple cache is able to store integers.",
            "[simple_cache]" )
{
    typedef shared_ptr<cache<string, int>> icache_t;
    typedef simple_cache<string, int>      simple_cache_t;

    icache_t icache = make_shared<simple_cache_t>( "catch_integers" );

    icache->set ( "a", 1 );
    icache->set ( "b", 2 );
    icache->set ( "d", 4 );

    CHECK ( icache->exists ( "a" ) == true );
    CHECK ( icache->exists ( "b" ) == true );
    CHECK ( icache->exists ( "d" ) == true );
    CHECK ( icache->exists ( "c" ) == false );
    CHECK ( icache->exists ( "e" ) == false );

    CHECK ( icache->get ( "a" ) == 1 );
    CHECK ( icache->get ( "b" ) == 2 );
    CHECK ( icache->get ( "d" ) == 4 );

    spdlog::set_level ( spdlog::level::off );
    CHECK ( icache->get ( "c" ) == 0 );
    CHECK ( icache->get ( "e" ) == 0 );
    spdlog::set_level ( spdlog::level::warn );

    icache->set ( "a", 11 );
    icache->set ( "b", 22 );
    icache->set ( "d", 44 );

    CHECK ( icache->exists ( "a" ) == true );
    CHECK ( icache->exists ( "b" ) == true );
    CHECK ( icache->exists ( "d" ) == true );
    CHECK ( icache->exists ( "c" ) == false );
    CHECK ( icache->exists ( "e" ) == false );

    CHECK ( icache->get ( "a" ) == 11 );
    CHECK ( icache->get ( "b" ) == 22 );
    CHECK ( icache->get ( "d" ) == 44 );

    spdlog::set_level ( spdlog::level::off );
    CHECK ( icache->get ( "c" ) == 0 );
    CHECK ( icache->get ( "e" ) == 0 );
    spdlog::set_level ( spdlog::level::warn );

    CHECK ( icache->evict ( "b" ) == 22 );
    CHECK ( icache->exists ( "b" ) == false );

    icache->clear();
    CHECK ( icache->exists ( "a" ) == false );
    CHECK ( icache->exists ( "b" ) == false );
    CHECK ( icache->exists ( "d" ) == false );
    CHECK ( icache->exists ( "c" ) == false );
    CHECK ( icache->exists ( "e" ) == false );
}

TEST_CASE ( "Check if simple cache is able to store strings.",
            "[simple_cache]" )
{
    typedef shared_ptr<cache<string, string>> scache_t;
    typedef simple_cache<string, string>      simple_cache_t;

    scache_t scache = make_shared<simple_cache_t>( "catch_strings" );

    scache->set ( "a", "string a" );
    scache->set ( "b", "string b" );
    scache->set ( "d", "string d" );

    CHECK ( scache->exists ( "a" ) == true );
    CHECK ( scache->exists ( "b" ) == true );
    CHECK ( scache->exists ( "d" ) == true );
    CHECK ( scache->exists ( "c" ) == false );
    CHECK ( scache->exists ( "e" ) == false );

    CHECK ( scache->get ( "a" ) == "string a" );
    CHECK ( scache->get ( "b" ) == "string b" );
    CHECK ( scache->get ( "d" ) == "string d" );

    spdlog::set_level ( spdlog::level::off );
    CHECK ( scache->get ( "c" ) == "" );
    CHECK ( scache->get ( "e" ) == "" );
    spdlog::set_level ( spdlog::level::warn );

    scache->set ( "a", "STRING AA" );
    scache->set ( "b", "STRING BB" );
    scache->set ( "d", "STRING DD" );

    CHECK ( scache->exists ( "a" ) == true );
    CHECK ( scache->exists ( "b" ) == true );
    CHECK ( scache->exists ( "d" ) == true );
    CHECK ( scache->exists ( "c" ) == false );
    CHECK ( scache->exists ( "e" ) == false );

    CHECK ( scache->get ( "a" ) == "STRING AA" );
    CHECK ( scache->get ( "b" ) == "STRING BB" );
    CHECK ( scache->get ( "d" ) == "STRING DD" );

    spdlog::set_level ( spdlog::level::off );
    CHECK ( scache->get ( "c" ) == "" );
    CHECK ( scache->get ( "e" ) == "" );
    spdlog::set_level ( spdlog::level::warn );

    CHECK ( scache->evict ( "b" ) == "STRING BB" );
    CHECK ( scache->exists ( "b" ) == false );

    scache->clear();
    CHECK ( scache->exists ( "a" ) == false );
    CHECK ( scache->exists ( "b" ) == false );
    CHECK ( scache->exists ( "d" ) == false );
    CHECK ( scache->exists ( "c" ) == false );
    CHECK ( scache->exists ( "e" ) == false );
}

TEST_CASE ( "Check if simple cache is able to store shared_ptr strings.",
            "[simple_cache]" )
{
    typedef shared_ptr<cache<string, shared_ptr<string>>> scache_t;
    typedef simple_cache<string, shared_ptr<string>>      simple_cache_t;

    scache_t scache = make_shared<simple_cache_t>( "catch_shared_strings" );

    scache->set ( "a", make_shared<string>( "string a" ) );
    scache->set ( "b", make_shared<string>( "string b" ) );
    scache->set ( "d", make_shared<string>( "string d" ) );

    CHECK ( scache->exists ( "a" ) == true );
    CHECK ( scache->exists ( "b" ) == true );
    CHECK ( scache->exists ( "d" ) == true );
    CHECK ( scache->exists ( "c" ) == false );
    CHECK ( scache->exists ( "e" ) == false );

    CHECK ( *scache->get ( "a" ) == "string a" );
    CHECK ( *scache->get ( "b" ) == "string b" );
    CHECK ( *scache->get ( "d" ) == "string d" );

    spdlog::set_level ( spdlog::level::off );
    CHECK ( scache->get ( "c" ) == nullptr );
    CHECK ( scache->get ( "e" ) == nullptr );
    spdlog::set_level ( spdlog::level::warn );

    scache->set ( "a", make_shared<string>( "STRING AA" ) );
    scache->set ( "b", make_shared<string>( "STRING BB" ) );
    scache->set ( "d", make_shared<string>( "STRING DD" ) );

    CHECK ( scache->exists ( "a" ) == true );
    CHECK ( scache->exists ( "b" ) == true );
    CHECK ( scache->exists ( "d" ) == true );
    CHECK ( scache->exists ( "c" ) == false );
    CHECK ( scache->exists ( "e" ) == false );

    CHECK ( *scache->get ( "a" ) == "STRING AA" );
    CHECK ( *scache->get ( "b" ) == "STRING BB" );
    CHECK ( *scache->get ( "d" ) == "STRING DD" );

    spdlog::set_level ( spdlog::level::off );
    CHECK ( scache->get ( "c" ) == nullptr );
    CHECK ( scache->get ( "e" ) == nullptr );
    spdlog::set_level ( spdlog::level::warn );

    CHECK ( *scache->evict ( "b" ) == "STRING BB" );
    CHECK ( scache->exists ( "b" ) == false );

    scache->clear();
    CHECK ( scache->exists ( "a" ) == false );
    CHECK ( scache->exists ( "b" ) == false );
    CHECK ( scache->exists ( "d" ) == false );
    CHECK ( scache->exists ( "c" ) == false );
    CHECK ( scache->exists ( "e" ) == false );
}

TEST_CASE ( "Check if simple cache with specified default.",
            "[simple_cache]" )
{
    typedef shared_ptr<cache<string, string>> scache_t;
    typedef simple_cache<string, string>      simple_cache_t;

    scache_t scache = make_shared<simple_cache_t>(
        "catch_strings_default",
        "empty" );

    scache->set ( "a", "string a" );
    scache->set ( "b", "string b" );
    scache->set ( "d", "string d" );

    CHECK ( scache->exists ( "a" ) == true );
    CHECK ( scache->exists ( "b" ) == true );
    CHECK ( scache->exists ( "d" ) == true );
    CHECK ( scache->exists ( "c" ) == false );
    CHECK ( scache->exists ( "e" ) == false );

    CHECK ( scache->get ( "a" ) == "string a" );
    CHECK ( scache->get ( "b" ) == "string b" );
    CHECK ( scache->get ( "d" ) == "string d" );

    spdlog::set_level ( spdlog::level::off );
    CHECK ( scache->get ( "c" ) == "empty" );
    CHECK ( scache->get ( "e" ) == "empty" );
    spdlog::set_level ( spdlog::level::warn );

    scache->set ( "a", "STRING AA" );
    scache->set ( "b", "STRING BB" );
    scache->set ( "d", "STRING DD" );

    CHECK ( scache->exists ( "a" ) == true );
    CHECK ( scache->exists ( "b" ) == true );
    CHECK ( scache->exists ( "d" ) == true );
    CHECK ( scache->exists ( "c" ) == false );
    CHECK ( scache->exists ( "e" ) == false );

    CHECK ( scache->get ( "a" ) == "STRING AA" );
    CHECK ( scache->get ( "b" ) == "STRING BB" );
    CHECK ( scache->get ( "d" ) == "STRING DD" );

    spdlog::set_level ( spdlog::level::off );
    CHECK ( scache->get ( "c" ) == "empty" );
    CHECK ( scache->get ( "e" ) == "empty" );
    spdlog::set_level ( spdlog::level::warn );

    CHECK ( scache->evict ( "b" ) == "STRING BB" );
    CHECK ( scache->exists ( "b" ) == false );

    scache->clear();
    CHECK ( scache->exists ( "a" ) == false );
    CHECK ( scache->exists ( "b" ) == false );
    CHECK ( scache->exists ( "d" ) == false );
    CHECK ( scache->exists ( "c" ) == false );
    CHECK ( scache->exists ( "e" ) == false );

    spdlog::set_level ( spdlog::level::off );
}
