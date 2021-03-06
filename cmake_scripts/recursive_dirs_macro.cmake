function (header_directories RETURN_LIST)
    file (GLOB_RECURSE NEW_LIST "*.h*")
    set (DIR_LIST "")
    foreach (FILE_PATH ${NEW_LIST})
        get_filename_component (DIR_PATH "${FILE_PATH}" PATH)
        set (DIR_LIST ${DIR_LIST} "${DIR_PATH}")
    endforeach ()
    list (REMOVE_DUPLICATES DIR_LIST)
    set (${RETURN_LIST} "${DIR_LIST}" PARENT_SCOPE)
endfunction ()
