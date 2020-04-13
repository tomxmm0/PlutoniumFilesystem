#pragma once

class Filesystem
{
private:
	FILE* handle_;
	std::string mode_;
public:
	Filesystem(const std::string& file, const std::string& mode);

	std::string Read();
	void Write(const std::string& str);
	void Close();

	static bool FileExists(const std::string& file);
	static bool ValidMode(const std::string& mode, const std::initializer_list<std::string>& list);
};
