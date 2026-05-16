#ifndef SIMPLEPTR_H
#define SIMPLEPTR_H

#include <utility>
#include <stdexcept>

template<typename T>
class SimplePtr {
private:
    T* ptr_;

public:
    explicit SimplePtr(T* ptr = nullptr)
        : ptr_(ptr) {}

    ~SimplePtr() {
        delete ptr_;
    }

    SimplePtr(const SimplePtr&) = delete;
    SimplePtr& operator=(const SimplePtr&) = delete;

    SimplePtr(SimplePtr&& other) noexcept
        : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }

    SimplePtr& operator=(SimplePtr&& other) noexcept {
        if (this != &other) {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    T& operator*() const {
        if (!ptr_) {
            throw std::runtime_error("Dereferencing null SimplePtr");
        }
        return *ptr_;
    }

    T* operator->() const {
        if (!ptr_) {
            throw std::runtime_error("Accessing null SimplePtr");
        }
        return ptr_;
    }

    T* get() const {
        return ptr_;
    }
};

#endif