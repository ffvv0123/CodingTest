#!/usr/bin/env python
import os
from urllib import parse

HEADER="""# 
# 백준 & 프로그래머스 문제 풀이 목록


"""

def main():
    content = ""
    content += HEADER
    
    directories = []
    solveds = []

    max_length = 50  # 파일 이름 최대 길이 설정

    for root, dirs, files in os.walk("."):
        dirs.sort()
        if root == '.':
            for dir in ('.git', '.github'):
                try:
                    dirs.remove(dir)
                except ValueError:
                    pass
            continue

        category = os.path.basename(root)
        
        if category == 'images':
            continue
        
        directory = os.path.basename(os.path.dirname(root))
        
        if directory == '.':
            continue
            
        if directory not in directories:
            if directory in ["백준", "프로그래머스"]:
                content += "## 📚 {}\n".format(directory)
            else:
                content += "### 🚀 {}\n".format(directory)
                content += "| 문제번호 | 링크 |\n"
                content += "| ----- | ----- |\n"
            directories.append(directory)

        for file in files:
            full_path = os.path.join(root, file)
            if len(full_path) > max_length:
                print(f"Skipping long file name: {full_path}")
                continue
            print(f"Processing file: {full_path}")
            if category not in solveds:
                content += "|{}|[링크]({})|\n".format(category, parse.quote(full_path))
                solveds.append(category)
                print("category : " + category)

    with open("README.md", "w") as fd:
        fd.write(content)
        
if __name__ == "__main__":
    main()
