#include "debug.h"

std::string glpp::gl_error_to_string ( GLenum err ) {
    switch ( err ) {
    case GL_NO_ERROR: return
            "(GL_NO_ERROR) No error has been recorded. The value of this "
            "symbolic constant is guaranteed to be 0.";

    case GL_INVALID_ENUM: return
            "(GL_INVALID_ENUM) An unacceptable value is specified for an "
            "enumerated argument. The offending command is ignored and has no "
            "other side effect than to set the error flag.";

    case GL_INVALID_VALUE: return
            "(GL_INVALID_VALUE) A numeric argument is out of range. The "
            "offending command is ignored and has no other side effect than to "
            "set the error flag.";

    case GL_INVALID_OPERATION: return
            "(GL_INVALID_OPERATION) The specified operation is not allowed in "
            "the current state. The offending command is ignored and has no "
            "other side effect than to set the error flag.";

    case GL_INVALID_FRAMEBUFFER_OPERATION: return
            "(GL_INVALID_FRAMEBUFFER_OPERATION) The framebuffer object is not "
            "complete. The offending command is ignored and has no other side "
            "effect than to set the error flag.";

    case GL_OUT_OF_MEMORY: return
            "(GL_OUT_OF_MEMORY) There is not enough memory left to execute the "
            "command. The state of the GL is undefined, except for the state "
            "of the error flags, after this error is recorded.";

    case GL_STACK_UNDERFLOW: return
            "(GL_STACK_UNDERFLOW) An attempt has been made to perform an "
            "operation that would cause an internal stack to underflow.";

    case GL_STACK_OVERFLOW: return
            "(GL_STACK_OVERFLOW) An attempt has been made to perform an "
            "operation that would cause an internal stack to overflow.";
    }

    return "Error code not recognised.";
}

bool glpp::gl_get_errors ( const std::string& file,
                           int                line,
                           const std::string& label ) {
    bool   found_errors = false;
    GLenum err;

    while ( ( err = glGetError() ) != GL_NO_ERROR ) {
        found_errors = true;
        std::cerr << "[" << label << "] " << file
                  << ":" << line
                  << " => " << glpp::gl_error_to_string ( err )
                  << std::endl;
    }

    return found_errors;
}

std::string glpp::gl_framebuffer_status_to_string ( GLenum status ) {
    switch ( status ) {
    case GL_FRAMEBUFFER_UNDEFINED: return
            "GL_FRAMEBUFFER_UNDEFINED: Specified framebuffer is the default read"
            " or draw framebuffer, but the default framebuffer does not exist.";

    case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT: return
            "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT: One or more of the "
            "framebuffer attachment points are framebuffer incomplete.";

    case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT: return
            "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT: The framebuffer does "
            "not have at least one image attached to it.";

    case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER: return
            "GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER: The value of "
            "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE is GL_NONE for one or more "
            "color attachment points named by GL_DRAW_BUFFERi.";

    case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER: return
            "GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER: GL_READ_BUFFER is not "
            "GL_NONE and the value of GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE is "
            "GL_NONE for the color attachment point named by GL_READ_BUFFER.";

    case GL_FRAMEBUFFER_UNSUPPORTED: return
            "GL_FRAMEBUFFER_UNSUPPORTED: The combination of internal formats of "
            "the attached images violates an implementation-dependent set of "
            "restrictions.";

    case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE: return
            "GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE: The value of "
            "GL_RENDERBUFFER_SAMPLES is not the same for all attached "
            "renderbuffers; if the value of GL_TEXTURE_SAMPLES is the not same "
            "for all attached textures; or, if the attached images are a mix of "
            "renderbuffers and textures, the value of GL_RENDERBUFFER_SAMPLES "
            "does not match the value of GL_TEXTURE_SAMPLES OR the value of "
            "GL_TEXTURE_FIXED_SAMPLE_LOCATIONS is not the same for all attached "
            "textures; or, if the attached images are a mix of renderbuffers "
            "and textures, the value of GL_TEXTURE_FIXED_SAMPLE_LOCATIONS is "
            "not GL_TRUE for all attached textures.";

    case GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS: return
            "GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS: One or more framebuffer "
            "attachments is layered, and any populated attachment is not "
            "layered, or if all populated color attachments are not from "
            "textures of the same target.";
    }

    return "Framebuffer complete.";
}
