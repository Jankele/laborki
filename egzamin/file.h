//file.h

#include <string>

struct File {
	typedef int OpenFlags;
	File(const std::string& file, OpenFlags flags);
	~File() noexcept;

	File(const File &rhs);
	File& operator=(const File& rhs);

	bool isValid() const noexcept;

	// i/o
	void write(const std::string& write);
	std::string readAll();
	std::string read(std::size_t n);

	static bool exists(const std::string& filename);

	private:
		typedef int Handle;
		Handle _handle;
};