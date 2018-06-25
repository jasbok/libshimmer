#include "external/catch/catch.hpp"

#include "common/json.h"

static const char* TAGS = "[json]";

void perform_checks ( const nlohmann::json j ) {
    // *INDENT-OFF*
    CHECK ( common::json::as_string ( j, { "field_a" } ) == "1" );

    CHECK ( common::json::as_string ( j, { "field_b" } ) == "value_b" );

    CHECK ( common::json::as_string ( j, { "field_c", "0" } ) == "0" );
    CHECK ( common::json::as_string ( j, { "field_c", "1" } ) == "1" );
    CHECK ( common::json::as_string ( j, { "field_c", "2" } ) == "2" );
    CHECK ( common::json::as_string ( j, { "field_c", "3" } ) == "3" );
    CHECK ( common::json::as_string ( j, { "field_c", "4" } ) == "4" );
    CHECK ( common::json::as_string ( j, { "field_c", "5" } ) == "5" );
    CHECK ( common::json::as_string ( j, { "field_c", "6" } ) == "6" );
    CHECK ( common::json::as_string ( j, { "field_c", "7" } ) == "7" );
    CHECK ( common::json::as_string ( j, { "field_c", "8" } ) == "8" );
    CHECK ( common::json::as_string ( j, { "field_c", "9" } ) == "9" );

    CHECK ( common::json::as_string ( j, { "field_d", "0" } ) == "0" );
    CHECK ( common::json::as_string ( j, { "field_d", "1" } ) == "1" );
    CHECK ( common::json::as_string ( j, { "field_d", "2" } ) == "2" );
    CHECK ( common::json::as_string ( j, { "field_d", "3" } ) == "3" );
    CHECK ( common::json::as_string ( j, { "field_d", "4" } ) == "4" );
    CHECK ( common::json::as_string ( j, { "field_d", "5" } ) == "5" );
    CHECK ( common::json::as_string ( j, { "field_d", "6" } ) == "6" );
    CHECK ( common::json::as_string ( j, { "field_d", "7" } ) == "7" );
    CHECK ( common::json::as_string ( j, { "field_d", "8" } ) == "8" );
    CHECK ( common::json::as_string ( j, { "field_d", "9" } ) == "9" );

    CHECK ( common::json::as_string ( j, { "field_e", "field_ea" } ) == "2" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_eb" } ) == "value_eb" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ec", "0" } ) == "10" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ec", "1" } ) == "11" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ec", "2" } ) == "12" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ec", "3" } ) == "13" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ec", "4" } ) == "14" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ec", "5" } ) == "15" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ec", "6" } ) == "16" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ec", "7" } ) == "17" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ec", "8" } ) == "18" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ec", "9" } ) == "19" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ed", "0" } ) == "10" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ed", "1" } ) == "11" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ed", "2" } ) == "12" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ed", "3" } ) == "13" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ed", "4" } ) == "14" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ed", "5" } ) == "15" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ed", "6" } ) == "16" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ed", "7" } ) == "17" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ed", "8" } ) == "18" );
    CHECK ( common::json::as_string ( j, { "field_e", "field_ed", "9" } ) == "19" );

    CHECK ( common::json::as_string ( j, { "field_f", "obj_a" } ) == "123" );
    CHECK ( common::json::as_string ( j, { "field_f", "obj_b" } ) == "456" );
    CHECK ( common::json::as_string ( j, { "field_f", "obj_c", "0" } ) == "20" );
    CHECK ( common::json::as_string ( j, { "field_f", "obj_c", "1" } ) == "21" );
    CHECK ( common::json::as_string ( j, { "field_f", "obj_c", "2" } ) == "22" );
    CHECK ( common::json::as_string ( j, { "field_f", "obj_c", "3" } ) == "23" );
    CHECK ( common::json::as_string ( j, { "field_f", "obj_c", "4" } ) == "24" );
    CHECK ( common::json::as_string ( j, { "field_f", "obj_d", "0" } ) == "str a" );
    CHECK ( common::json::as_string ( j, { "field_f", "obj_d", "1" } ) == "str b" );
    CHECK ( common::json::as_string ( j, { "field_f", "obj_d", "2" } ) == "str c" );
    CHECK ( common::json::as_string ( j, { "field_f", "obj_e", "field" } ) == "value" );

    CHECK ( common::json::as_string ( j, { "field_bool_true" } ) == "1" );

    CHECK ( common::json::as_string ( j, { "field_bool_false" } ) == "0" );

    CHECK ( common::json::as_string ( j, { "field_int_12" } ) == "12" );

    CHECK ( common::json::as_string ( j, { "field_int_neg_13" } ) == "-13" );

    CHECK_THAT ( common::json::as_string ( j, { "field_float_14.56" } ),
                 Catch::Matchers::StartsWith ( "14.56" ) );

    CHECK_THAT ( common::json::as_string ( j, { "field_float_neg_15.56" } ),
                 Catch::Matchers::StartsWith ( "-15.56" ) );

    CHECK ( common::json::as_string ( j, { "field_str_text" } ) == "text" );


    CHECK_THROWS_AS( common::json::as_string ( j, { "field_e", "obj_a" } ),
                     common::json::field_absent_exception );
    CHECK_THROWS_WITH( common::json::as_string ( j, { "field_e", "obj_a" } ),
                       Catch::Matchers::Contains ( "field_e.obj_a" ) );

    CHECK_THROWS_AS( common::json::as_string ( j, { "field_e", "obj_a" } ),
                     common::json::field_absent_exception );
    CHECK_THROWS_WITH( common::json::as_string ( j, { "field_e", "field_ec", "20" } ),
                       Catch::Matchers::Contains ( "field_e.field_ec.20" ) );

 // *INDENT-ON*
}

TEST_CASE ( "Get value of json field using path. (json c++ constructor)",
            TAGS ) {
    using namespace nlohmann;

    // *INDENT-OFF*
    json j = {
        {"field_a", 1},
        {"field_b", "value_b"},
        {"field_c", {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}},
        {"field_d", {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}},
        {"field_e", {
             {"field_ea", 2},
             {"field_eb", "value_eb"},
             {"field_ec", {10, 11, 12, 13, 14, 15, 16, 17, 18, 19}},
             {"field_ed", {"10", "11", "12", "13", "14", "15", "16", "17", "18", "19"}}
         }},
        {"field_f", {
            {"obj_a", 123},
            {"obj_b", "456"},
            {"obj_c", { 20, 21, 22, 23, 24 }},
            {"obj_d", { "str a", "str b", "str c" }},
            {"obj_e", {{ "field", "value" }} }
        }},
        {"field_bool_true", true},
        {"field_bool_false", false},
        {"field_int_12", 12},
        {"field_int_neg_13", -13},
        {"field_float_14.56", 14.56f},
        {"field_float_neg_15.56", -15.56f},
        {"field_str_text", "text"}
    };
 // *INDENT-ON*

    perform_checks ( j );
}

TEST_CASE ( "Get value of json field using path. (json raw string constructor)",
            TAGS ) {
    using namespace nlohmann;

    // *INDENT-OFF*
    json j = json::parse(R"(
           {
              "field_a": 1,
              "field_b": "value_b",
              "field_c": [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
              "field_d": ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"],
              "field_e": {
                   "field_ea": 2,
                   "field_eb": "value_eb",
                   "field_ec": [10, 11, 12, 13, 14, 15, 16, 17, 18, 19],
                   "field_ed": ["10", "11", "12", "13", "14", "15", "16", "17", "18", "19"]
              },
              "field_f": {
                  "obj_a": 123,
                  "obj_b": "456",
                  "obj_c": [ 20, 21, 22, 23, 24 ],
                  "obj_d": [ "str a", "str b", "str c" ],
                  "obj_e": {
                         "field": "value"
                  }
              },
              "field_bool_true": true,
              "field_bool_false": false,
              "field_int_12": 12,
              "field_int_neg_13": -13,
              "field_float_14.56": 14.56,
              "field_float_neg_15.56": -15.56,
              "field_str_text": "text"
            }
           )");
 // *INDENT-ON*

    perform_checks ( j );
}
