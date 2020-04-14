#include "pch.h"
#include "Filesystem.hpp"

Filesystem::Filesystem(const std::string& file, const std::string& mode)
{
	auto parent_path = std::filesystem::absolute(std::filesystem::path(file)).parent_path();

	if (std::filesystem::current_path().compare(parent_path) > 0)
	{
		throw std::exception("[Plutonium Filesystem]: File must exist within the game folder");
	}

	if (!FileExists(file))
	{
		throw std::exception(("[Plutonium Filesystem]: " + file + " does not exist.").data());
	}


	if (ValidMode(mode, { "r", "w", "a", "r+", "w+", "a+" }))
	{
		fopen_s(&handle_, ("./" + file).data(), mode.data());
		mode_ = mode;
	}
	else
	{
		throw std::exception("[Plutonium Filesystem]: Invalid file mode.");
	}
}

Filesystem::~Filesystem()
{
	if (handle_ != nullptr)
	{
		fclose(handle_);
	}
}

std::string Filesystem::Read()
{
	if (ValidMode(mode_, { "r", "r+", "w+", "a+" }))
	{
		std::vector<char> content;

		int c = fgetc(handle_);
		while (c != EOF)
		{
			content.emplace_back(static_cast<char>(c));
			c = fgetc(handle_);
		}
		fseek(handle_, 0, SEEK_SET);

		return std::string(content.begin(), content.end());
	}
	else
	{
		throw std::exception("[Plutonium Filesystem]: Invalid mode for reading.");
	}
}

void Filesystem::Write(const std::string& text)
{
	if (ValidMode(mode_, { "w", "a", "r+", "w+", "a+" }))
	{
		fprintf_s(handle_, text.data());
		fseek(handle_, 0, SEEK_SET);
	}
	else
	{
		throw std::exception("[Plutonium Filesystem]: Invalid mode for writing/appending.");
	}
}

void Filesystem::Close()
{
	if (handle_ != nullptr)
	{
		fclose(handle_);
	}
}

bool Filesystem::FileExists(const std::string& file)
{
	return std::filesystem::exists(file);
}

bool Filesystem::ValidMode(const std::string& mode, const std::initializer_list<std::string>& list)
{
	auto iter = std::find(list.begin(), list.end(), mode);

	return iter != list.end();
}
