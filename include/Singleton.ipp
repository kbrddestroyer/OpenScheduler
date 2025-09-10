namespace Utils {
    template <typename T>
    std::shared_ptr<T> Singleton<T>::instance() {
        static std::shared_ptr<T> instance = std::make_shared<T>();
        return instance;
    }
} // Utils