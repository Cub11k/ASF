#include "main.hpp"

int ASFHeaderParser(int argc, char *argv[])
{
    std::vector<std::unique_ptr<Object>> objects{};
    std::ifstream in{};
    try {
        if (argc < 2) {
            throw std::runtime_error("No file provided");
        }
        in.open(argv[1], std::ios::in | std::ios::binary);
        if (in.is_open()) {
            std::cout << argv[1] << " file is now open" << std::endl;
        } else {
            throw std::runtime_error("File is not open");
        }
        Object tmp{};
        while (in >> tmp) { // input guid and size
            std::unique_ptr<Object> object{ObjectFactory(tmp)}; // create new ptr to specific object
            in >> *object; // input specific object
            objects.push_back(std::move(object)); // add specific object to vector
        }
        throw std::invalid_argument("Finished input");
    } catch (const std::runtime_error &err) {
        std::cout << "Runtime error: " << err.what() << std::endl;
        in.close();
        return 1;
    } catch (const std::invalid_argument &err) {
        std::cout << err.what() << std::endl;
        for (auto &obj : objects) {
            std::cout << *obj;
        }
    }
    in.close();
    return 0;
}

int main(int argc, char *argv[])
{
    return ASFHeaderParser(argc, argv);
}