#include "external/catch/catch.hpp"

#include "common/env.h"

static const char* TAGS = "[environment]";

TEST_CASE ( "Read all environment variables.", TAGS ) {
    const char* var_a = "SHIMMER_COMMON_CATCH_TEST_A=test_value_a";
    const char* var_b = "SHIMMER_COMMON_CATCH_TEST_B=test_value_b";
    const char* var_c = "SHIMMER_COMMON_CATCH_TEST_C=test_value_c";
    const char* var_d = "SHIMMER_COMMON_CATCH_TEST_D=test_value_d";

    putenv ( const_cast<char*>( var_a ) );
    putenv ( const_cast<char*>( var_b ) );
    putenv ( const_cast<char*>( var_c ) );
    putenv ( const_cast<char*>( var_d ) );

    auto evars = common::env::evars();

    REQUIRE ( evars.size() > 4 );
    REQUIRE ( evars.find ( "SHIMMER_COMMON_CATCH_TEST_A" ) != evars.end() );
    REQUIRE ( evars.find ( "SHIMMER_COMMON_CATCH_TEST_B" ) != evars.end() );
    REQUIRE ( evars.find ( "SHIMMER_COMMON_CATCH_TEST_C" ) != evars.end() );
    REQUIRE ( evars.find ( "SHIMMER_COMMON_CATCH_TEST_D" ) != evars.end() );

    CHECK ( evars.at ( "SHIMMER_COMMON_CATCH_TEST_A" ) == "test_value_a" );
    CHECK ( evars.at ( "SHIMMER_COMMON_CATCH_TEST_B" ) == "test_value_b" );
    CHECK ( evars.at ( "SHIMMER_COMMON_CATCH_TEST_C" ) == "test_value_c" );
    CHECK ( evars.at ( "SHIMMER_COMMON_CATCH_TEST_D" ) == "test_value_d" );
}

TEST_CASE ( "Find all environment variables matching a regex.", TAGS ) {
    const char* var_a = "SHIMMER_COMMON_CATCH_TEST_A=test_value_a";
    const char* var_b = "SHIMMER_COMMON_CATCH_TEST_B=test_value_b";
    const char* var_c = "SHIMMER_COMMON_CATCH_TEST_C=test_value_c";
    const char* var_d = "SHIMMER_COMMON_CATCH_TEST_D=test_value_d";

    const char* var_e = "COMMON_SHIMMER_CATCH_TEST_E=test_value_e";
    const char* var_f = "COMMON_SHIMMER_CATCH_TEST_F=test_value_f";
    const char* var_g = "COMMON_CATCH_TEST_G_SHIMMER=test_value_g";

    putenv ( const_cast<char*>( var_a ) );
    putenv ( const_cast<char*>( var_b ) );
    putenv ( const_cast<char*>( var_c ) );
    putenv ( const_cast<char*>( var_d ) );
    putenv ( const_cast<char*>( var_e ) );
    putenv ( const_cast<char*>( var_f ) );
    putenv ( const_cast<char*>( var_g ) );

    REQUIRE ( common::env::evar ( "COMMON_SHIMMER_CATCH_TEST_E" )
              == "test_value_e" );
    REQUIRE ( common::env::evar ( "COMMON_SHIMMER_CATCH_TEST_F" )
              == "test_value_f" );
    REQUIRE ( common::env::evar ( "COMMON_CATCH_TEST_G_SHIMMER" )
              == "test_value_g" );

    auto evars = common::env::find_all ( std::regex ( "^SHIMMER_.*" ) );
    REQUIRE ( evars.size() == 4 );
    REQUIRE ( evars.find ( "SHIMMER_COMMON_CATCH_TEST_A" ) != evars.end() );
    REQUIRE ( evars.find ( "SHIMMER_COMMON_CATCH_TEST_B" ) != evars.end() );
    REQUIRE ( evars.find ( "SHIMMER_COMMON_CATCH_TEST_C" ) != evars.end() );
    REQUIRE ( evars.find ( "SHIMMER_COMMON_CATCH_TEST_D" ) != evars.end() );

    CHECK ( evars.at ( "SHIMMER_COMMON_CATCH_TEST_A" ) == "test_value_a" );
    CHECK ( evars.at ( "SHIMMER_COMMON_CATCH_TEST_B" ) == "test_value_b" );
    CHECK ( evars.at ( "SHIMMER_COMMON_CATCH_TEST_C" ) == "test_value_c" );
    CHECK ( evars.at ( "SHIMMER_COMMON_CATCH_TEST_D" ) == "test_value_d" );
}
