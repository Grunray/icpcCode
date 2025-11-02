import PyPDF2
import os
import sys
from typing import List
def extract_pdf_pages(input_path: str, output_path: str, pages: List[int]) -> bool:
    """
    从PDF文件中提取指定页码并保存为新的PDF文件
    
    参数:
        input_path: 输入PDF文件路径
        output_path: 输出PDF文件路径
        pages: 要提取的页码列表(注意：PDF页码从1开始)
    
    返回:
        操作成功返回True，否则返回False
    """
    try:
        # 检查输入文件是否存在
        if not os.path.exists(input_path):
            print(f"错误: 输入文件 '{input_path}' 不存在")
            return False
        
        # 打开输入PDF文件
        with open(input_path, 'rb') as input_file:
            pdf_reader = PyPDF2.PdfReader(input_file)
            pdf_writer = PyPDF2.PdfWriter()
            
            # 检查页码是否有效
            total_pages = len(pdf_reader.pages)
            valid_pages = []
            
            for page_num in pages:
                if page_num < 1 or page_num > total_pages:
                    print(f"警告: 页码 {page_num} 超出范围(总页数: {total_pages})，已跳过")
                    continue
                
                valid_pages.append(page_num)
                # PDF阅读器使用0基索引，所以需要减1
                pdf_writer.add_page(pdf_reader.pages[page_num - 1])
            
            # 如果没有有效页码被添加
            if not valid_pages:
                print("错误: 没有有效页码被提取")
                return False
            
            # 写入输出文件
            with open(output_path, 'wb') as output_file:
                pdf_writer.write(output_file)
            
            print(f"成功提取页码 {valid_pages} 到 '{output_path}'")
            return True
    
    except Exception as e:
        print(f"处理过程中发生错误: {str(e)}")
        return False

def parse_page_numbers(page_str: str) -> List[int]:
    """解析页码字符串为页码列表，支持范围格式如"1-3,5,7-9" """
    pages = []
    parts = page_str.split(',')
    
    for part in parts:
        part = part.strip()
        if '-' in part:
            # 处理范围格式
            try:
                start, end = map(int, part.split('-'))
                if start > end:
                    print(f"警告: 无效的范围 {part}，已跳过")
                    continue
                pages.extend(range(start, end + 1))
            except ValueError:
                print(f"警告: 无效的页码格式 {part}，已跳过")
        else:
            # 处理单个页码
            try:
                page = int(part)
                pages.append(page)
            except ValueError:
                print(f"警告: 无效的页码 {part}，已跳过")
    
    # 去重并排序
    return sorted(list(set(pages)))

if __name__ == "__main__":
    # 获取用户输入
    input_pdf = input("请输入PDF文件路径: ").strip()
    output_pdf = input("请输入输出文件路径: ").strip()
    page_input = input("请输入要提取的页码(支持格式: 1-3,5,7-9): ").strip()
    
    # 解析页码
    pages_to_extract = parse_page_numbers(page_input)
    
    if not pages_to_extract:
        print("错误: 未提供有效页码")
        sys.exit(1)
    
    # 执行提取操作
    success = extract_pdf_pages(input_pdf, output_pdf, pages_to_extract)
    
    if not success:
        sys.exit(1)
    