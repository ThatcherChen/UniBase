#pragma once

#include <cerrno>
#include <cstring>
#include <string>
#include <vector>

class UniBaseError : public std::exception {
   public:
    UniBaseError() : _msg("Error: ") {}

    UniBaseError(const std::string &msg) : _msg("Error: " + msg) {}

    const char *what() const noexcept override { return _msg.c_str(); }

    int get_msg_len() { return _msg.length(); }

    std::string _msg;
};

class InternalError : public UniBaseError {
   public:
    InternalError(const std::string &msg) : UniBaseError(msg) {}
};

// PF errors
class UnixError : public UniBaseError {
   public:
    UnixError() : UniBaseError(strerror(errno)) {}
};

class FileNotOpenError : public UniBaseError {
   public:
    FileNotOpenError(int fd) : UniBaseError("Invalid file descriptor: " + std::to_string(fd)) {}
};

class FileNotClosedError : public UniBaseError {
   public:
    FileNotClosedError(const std::string &filename) : UniBaseError("File is opened: " + filename) {}
};

class FileExistsError : public UniBaseError {
   public:
    FileExistsError(const std::string &filename) : UniBaseError("File already exists: " + filename) {}
};

class FileNotFoundError : public UniBaseError {
   public:
    FileNotFoundError(const std::string &filename) : UniBaseError("File not found: " + filename) {}
};

// RM errors
class RecordNotFoundError : public UniBaseError {
   public:
    RecordNotFoundError(int page_no, int slot_no)
        : UniBaseError("Record not found: (" + std::to_string(page_no) + "," + std::to_string(slot_no) + ")") {}
};

class InvalidRecordSizeError : public UniBaseError {
   public:
    InvalidRecordSizeError(int record_size) : UniBaseError("Invalid record size: " + std::to_string(record_size)) {}
};

// IX errors
class InvalidColLengthError : public UniBaseError {
   public:
    InvalidColLengthError(int col_len) : UniBaseError("Invalid column length: " + std::to_string(col_len)) {}
};

class IndexEntryNotFoundError : public UniBaseError {
   public:
    IndexEntryNotFoundError() : UniBaseError("Index entry not found") {}
};

// SM errors
class DatabaseNotFoundError : public UniBaseError {
   public:
    DatabaseNotFoundError(const std::string &db_name) : UniBaseError("Database not found: " + db_name) {}
};

class DatabaseExistsError : public UniBaseError {
   public:
    DatabaseExistsError(const std::string &db_name) : UniBaseError("Database already exists: " + db_name) {}
};

class TableNotFoundError : public UniBaseError {
   public:
    TableNotFoundError(const std::string &tab_name) : UniBaseError("Table not found: " + tab_name) {}
};

class TableExistsError : public UniBaseError {
   public:
    TableExistsError(const std::string &tab_name) : UniBaseError("Table already exists: " + tab_name) {}
};

class ColumnNotFoundError : public UniBaseError {
   public:
    ColumnNotFoundError(const std::string &col_name) : UniBaseError("Column not found: " + col_name) {}
};

class IndexNotFoundError : public UniBaseError {
   public:
    IndexNotFoundError(const std::string &tab_name, const std::vector<std::string> &col_names) {
        _msg += "Index not found: " + tab_name + ".(";
        for(size_t i = 0; i < col_names.size(); ++i) {
            if(i > 0) _msg += ", ";
            _msg += col_names[i];
        }
        _msg += ")";
    }
};

class IndexExistsError : public UniBaseError {
   public:
    IndexExistsError(const std::string &tab_name, const std::vector<std::string> &col_names) {
        _msg += "Index already exists: " + tab_name + ".(";
        for(size_t i = 0; i < col_names.size(); ++i) {
            if(i > 0) _msg += ", ";
            _msg += col_names[i];
        }
        _msg += ")";
    }
};

// QL errors
class InvalidValueCountError : public UniBaseError {
   public:
    InvalidValueCountError() : UniBaseError("Invalid value count") {}
};

class StringOverflowError : public UniBaseError {
   public:
    StringOverflowError() : UniBaseError("String is too long") {}
};

class IncompatibleTypeError : public UniBaseError {
   public:
    IncompatibleTypeError(const std::string &lhs, const std::string &rhs)
        : UniBaseError("Incompatible type error: lhs " + lhs + ", rhs " + rhs) {}
};

class AmbiguousColumnError : public UniBaseError {
   public:
    AmbiguousColumnError(const std::string &col_name) : UniBaseError("Ambiguous column: " + col_name) {}
};

class PageNotExistError : public UniBaseError {
   public:
    PageNotExistError(const std::string &table_name, int page_no)
        : UniBaseError("Page " + std::to_string(page_no) + " in table " + table_name + "not exits") {}
};