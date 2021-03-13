class vai_string
{
private:
	char* v_str_ = nullptr;
	size_t size_ = 0;

public:
	void operator = (const std::string& basic_string)
	{
		size_ = basic_string.size();
		free(v_str_);
		v_str_ = static_cast<char*>(malloc(size_));
		if (v_str_ == NULL)
		{
			std::cout
				<< "ERROR > VAI_STRING > MALLOC NULL"
				<< std::endl;
		}
		else
		{
			for (size_t i = 0; i < size_; i++)
			{
				v_str_[i] = basic_string[i];
			}
		}
	}

	void operator += (const std::string& basic_string)
	{
		const size_t _size_mlc = size_;
		size_ = _size_mlc + basic_string.size();
		char* _v_str_mlc = v_str_;
		if (_v_str_mlc == NULL)
		{
			std::cout
				<< "ERROR > VAI_STRING > MALLOC NULL"
				<< std::endl;
		}
		else
		{
			free(v_str_);
			v_str_ = static_cast<char*>(malloc(size_));
			for (auto i = 0; i < _size_mlc; i++)
			{
				v_str_[i] = _v_str_mlc[i];
			}
			if (v_str_ == NULL)
			{
				std::cout
					<< "ERROR > VAI_STRING > MALLOC NULL"
					<< std::endl;
			}
			else
			{
				for (auto i = _size_mlc; i < size_; i++)
				{
					v_str_[i] = basic_string[i - _size_mlc];
				}
			}
		}
	}

	char operator[] (const unsigned int index) const
	{
		if (index < size_)
		{
			return v_str_[index];
		}
		return NULL;
	}

	size_t size() const
	{
		return size_;
	}

	
};
