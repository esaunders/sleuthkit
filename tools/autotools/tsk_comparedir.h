#include <set>
#include <stdlib.h>

struct ltstr
{
  bool operator()(char* s1, char* s2) const
  {
    return strcmp(s1, s2) > 0;
  }
};

class TskCompareDir : public TskAuto {
public:
    uint8_t compareDirs(TSK_OFF_T soffset, TSK_INUM_T inum, const TSK_TCHAR * lcl_dir);

private:
    std::set<char*, ltstr> m_filesInImg; 
    bool m_missDirFile;
    
    virtual TSK_RETVAL_ENUM processFile(TSK_FS_FILE * fs_file, const char *path); 
	virtual TSK_FILTER_ENUM filterVol(const TSK_VS_PART_INFO * vs_part);
    uint8_t compareLclFiles(const TSK_TCHAR* base_dir, const TSK_TCHAR *dir);
};
