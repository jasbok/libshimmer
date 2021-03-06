#include "window.h"

#include "shim.h"

#include "common/str.h"

window::window( class shim* shim )
    : _shim ( shim )
{}

void window::title ( const char* title, const char* icon ) {
    std::string title_str = title ? std::string ( title ) : "";
    std::string icon_str  = icon ? std::string ( icon ) : "";

    _title = title_str;
    _icon  = icon_str;

    sym::SDL_WM_SetCaption ( ( "[shim] " + title_str ).c_str(), icon );
}

void window::title ( char** title, char** icon )
{
    if ( !_title.empty() ) {
        *title =
            static_cast<char*>( malloc ( sizeof( char ) * _title.size() ) );
        _title.copy ( *title, _title.size() );
    }


    if ( !_icon.empty() ) {
        *icon = static_cast<char*>( malloc ( sizeof( char ) * _icon.size() ) );
        _icon.copy ( *icon, _icon.size() );
    }
}
