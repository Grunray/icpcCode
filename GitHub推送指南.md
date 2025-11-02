# GitHub 代码推送指南

本文档介绍如何将本地代码推送到 GitHub 仓库（假设已有 GitHub 账号）。

## 快速开始示例

上传代码到 GitHub 的完整命令：

前提是你已经初始化了本地仓库，也就是你在编译器的git界面初始化了仓库，然后逐行执行命令即可。
git界面：左侧侧边栏有个图标，一般是两个圈被两条线连着的图标，有“初始化”等字样的就是。

```bash
# 1. 配置 Git 用户信息（首次使用需要配置，全局配置只需配置一次）
# 这里用的是我的github账户，你们可以自己创建，然年我邀请你们以协作者的形式管理仓库
# 使用 --global 参数：所有项目共用，切换项目不需要重新配置（推荐）
git config --global user.email "3131309414@qq.com"    # 全局配置邮箱
git config --global user.name "Grunray"               # 全局配置用户名
# 或者不使用 --global：仅当前项目使用（切换项目需要重新配置）
# git config user.email "3131309414@qq.com"
# git config user.name "Grunray"

# 2. 添加所有文件到暂存区
git add .                                     # 添加当前目录所有文件

# 3. 提交更改 （最好使用英文，避免中文乱码问题）
# 引号中的内容是你这次提交的代码的说明，如“新增了某项功能、修复了某个bug”
git commit -m "Initial commit: Add all code files"  # 创建初始提交

# 4. 添加远程仓库
git remote add origin https://github.com/Grunray/仓库的名称.git  # 添加 GitHub 仓库地址

# 5. 确保分支名为 main
# 确保代码无误的情况下将分支命名为main，不确定的情况下命名为其他的，下方的“main”同理，名称需要相同
git branch -M main                            # 将分支重命名为 main

# 6. 推送到 GitHub
git push -u origin main                       # 首次推送，-u 参数设置上游分支
```

### ⚠️ 重要说明

1. **提交（commit）≠ 推送（push）**
   - 在 IDE 的 Git 界面点击"提交"只是将更改保存到**本地仓库**
   - **不会自动推送到 GitHub**，需要额外点击"推送"（Push）按钮
   - 或者使用命令：`git push`

2. **远程仓库配置是项目独立的**
   - 每个项目都需要单独执行 `git remote add origin` 来连接对应的 GitHub 仓库
   - 切换项目后，如果新项目还没有配置远程仓库，需要重新配置
   - 可以通过 `git remote -v` 查看当前项目的远程仓库配置

3. **用户信息配置**
   - 如果使用 `git config --global` 配置（全局配置），所有项目都会使用这个配置，**切换项目不需要重新配置**
   - 如果使用 `git config` 配置（仅当前项目），切换项目后需要重新配置
   - 推荐使用全局配置：`git config --global user.name "你的名字"`

### 📝 日常使用流程（配置完成后）

1. 在 IDE 中修改代码
2. 点击 Git 界面 → "提交"（Commit）→ 填写提交信息 → 提交
3. 点击 "推送"（Push）→ 代码上传到 GitHub

**注意**：如果是新项目，首次需要执行上面的完整流程配置远程仓库。

## 基本流程（如果看了快速开始示例就不用仔细看下方的内容了，下方内容是补充说明）
## 目录

1. [在 GitHub 上创建仓库](#在-github-上创建仓库)
2. [本地 Git 配置](#本地-git-配置)
3. [添加文件并提交](#添加文件并提交)
4. [连接远程仓库并推送](#连接远程仓库并推送)
5. [常见问题](#常见问题)

---

## 在 GitHub 上创建仓库

1. 登录 https://github.com
2. 点击右上角 **"+"** → **"New repository"**
3. 填写仓库信息：
   - **Repository name**：仓库名称（只能使用字母、数字、连字符和下划线）
   - **Description**：描述（可选）
   - **Public/Private**：选择公开或私有
   - **⚠️ 重要**：不要勾选 Add README、Add .gitignore、Choose license
4. 点击 **"Create repository"**
5. 复制仓库 URL：
   - HTTPS：`https://github.com/用户名/仓库名.git`
   - SSH：`git@github.com:用户名/仓库名.git`

---

## 本地 Git 配置

### 1. 初始化 Git 仓库

进入项目文件夹，初始化 Git（如果尚未初始化）：
```bash
git init
```

### 2. 配置 Git 用户信息（首次使用）

```bash
# 全局配置（推荐）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱"

# 或仅当前项目配置
git config user.name "你的名字"
git config user.email "你的邮箱"
```

## 添加文件并提交

```bash
# 1. 添加所有文件到暂存区
git add .

# 2. 提交更改
git commit -m "提交说明"

# 示例：
# git commit -m "Initial commit: 添加所有代码文件"
# git commit -m "修复登录bug"
```

---

## 连接远程仓库并推送

```bash
# 1. 添加远程仓库（HTTPS 方式）
git remote add origin https://github.com/用户名/仓库名.git

# 或 SSH 方式（需先配置 SSH 密钥）
git remote add origin git@github.com:用户名/仓库名.git

# 2. 确保分支名为 main
git branch -M main

# 3. 首次推送
git push -u origin main

# 4. 后续推送（可直接使用）
git push
```

---

## 常见问题

### 问题 1：推送时要求输入密码

GitHub 已不支持密码认证，需要使用 **Personal Access Token**：

1. GitHub → Settings → Developer settings → Personal access tokens → Tokens (classic)
2. Generate new token (classic) → 勾选 `repo` 权限 → Generate
3. 复制 token（只显示一次），推送时在密码框输入 token

**推荐：使用 SSH 密钥**
```bash
# 生成 SSH 密钥
ssh-keygen -t ed25519 -C "你的邮箱"

# 复制公钥
cat ~/.ssh/id_ed25519.pub

# 在 GitHub 添加 SSH 密钥：Settings → SSH and GPG keys → New SSH key
# 然后使用 SSH URL
git remote set-url origin git@github.com:用户名/仓库名.git
```

### 问题 2：远程仓库已有文件

```bash
git pull origin main --allow-unrelated-histories
git push -u origin main
```

### 问题 3：更换远程仓库

```bash
git remote remove origin
git remote add origin 新仓库URL
```

### 问题 4：移除已提交的文件

```bash
git rm --cached 文件名
git commit -m "移除不需要的文件"
git push
```

---

## 日常工作流程

```bash
git add .
git commit -m "提交说明"
git push
```

**常用命令：**
- `git status` - 查看状态
- `git log` - 查看提交历史
- `git branch` - 查看分支