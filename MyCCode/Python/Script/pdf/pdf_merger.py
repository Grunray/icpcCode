from PyPDF2 import PdfMerger
import os

def merge_pdfs(input_pdf1, input_pdf2, output_pdf):
    """
    将两个PDF文件合并，第二个PDF会被添加到第一个PDF的末尾
    
    参数:
        input_pdf1: 第一个PDF文件路径（会作为合并后的开头）
        input_pdf2: 第二个PDF文件路径（会被添加到末尾）
        output_pdf: 合并后的PDF文件输出路径
    """
    # 检查输入文件是否存在
    for pdf_file in [input_pdf1, input_pdf2]:
        if not os.path.exists(pdf_file):
            raise FileNotFoundError(f"文件不存在: {pdf_file}")
        if not pdf_file.lower().endswith('.pdf'):
            raise ValueError(f"不是PDF文件: {pdf_file}")

    # 创建PdfMerger对象
    merger = PdfMerger()

    try:
        # 添加第一个PDF
        merger.append(input_pdf1)
        print(f"已添加: {input_pdf1}")
        
        # 添加第二个PDF
        merger.append(input_pdf2)
        print(f"已添加: {input_pdf2}")
        
        # 确保输出目录存在
        output_dir = os.path.dirname(output_pdf)
        if output_dir and not os.path.exists(output_dir):
            os.makedirs(output_dir)
        
        # 写入合并后的PDF
        merger.write(output_pdf)
        print(f"PDF合并完成，输出文件: {output_pdf}")
        print(f"文件保存路径: {os.path.abspath(output_pdf)}")
        
    except Exception as e:
        print(f"合并过程中发生错误: {str(e)}")
    finally:
        # 关闭merger
        merger.close()

def get_valid_pdf_path(prompt):
    """获取有效的PDF文件路径"""
    while True:
        path = input(prompt).strip()
        # 处理可能的引号
        if (path.startswith('"') and path.endswith('"')) or (path.startswith("'") and path.endswith("'")):
            path = path[1:-1]
            
        # 检查路径是否存在
        if not os.path.exists(path):
            print(f"错误: 文件不存在 - {path}")
            continue
            
        # 检查是否为PDF文件
        if not path.lower().endswith('.pdf'):
            print(f"错误: 不是PDF文件 - {path}")
            continue
            
        return path

def get_output_path(prompt):
    """获取输出文件路径"""
    while True:
        path = input(prompt).strip()
        # 处理可能的引号
        if (path.startswith('"') and path.endswith('"')) or (path.startswith("'") and path.endswith("'")):
            path = path[1:-1]
            
        # 确保文件名以.pdf结尾
        if not path.lower().endswith('.pdf'):
            path += '.pdf'
            
        # 检查是否会覆盖已有文件
        if os.path.exists(path):
            overwrite = input(f"文件 '{path}' 已存在，是否覆盖? (y/n): ").strip().lower()
            if overwrite != 'y' and overwrite != 'yes':
                continue
                
        return path

if __name__ == "__main__":
    print("===== PDF文件合并工具 =====")
    print("请输入要合并的两个PDF文件路径，以及合并后的输出路径")
    print("提示: 可以输入绝对路径或相对路径，路径中包含空格时可以用引号括起来")
    print()
    
    # 获取第一个PDF文件路径
    pdf1 = get_valid_pdf_path("请输入第一个PDF文件路径 (将作为开头): ")
    
    # 获取第二个PDF文件路径
    pdf2 = get_valid_pdf_path("请输入第二个PDF文件路径 (将添加到末尾): ")
    
    # 获取输出文件路径
    output = get_output_path("请输入合并后的PDF文件保存路径: ")
    
    print()
    print("开始合并PDF文件...")
    merge_pdfs(pdf1, pdf2, output)
