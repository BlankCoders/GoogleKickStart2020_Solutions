# Hacktoberfest-2020

Hacktoberfest® is open to everyone in our global community. Whether you’re a developer or a student learning to code.

* Hacktoberfest is a celebration open to everyone in our global community.
* Pull requests can be made in any GitHub-hosted repositories/projects.
* You can sign up anytime between October 1 and October 31.

### Visit [Hacktoberfest](https://hacktoberfest.digitalocean.com/) Website to know more.

### How to register:

* Go to <https://github.com> & create an account.
* Then register at <https://hacktoberfest.digitalocean.com/register> by logging through your GitHub Account and you're all set to contribute for Hacktoberfest.

### But there are some rules for Hacktoberfest and here we go:
To earn your Hacktoberfest tee or tree reward, you must register and make four valid pull requests (PRs) between October 1-31, 2020 (in any time zone). PRs can be made to any public repo on GitHub, not only the ones with issues labeled Hacktoberfest. If a maintainer reports your pull request as spam or behavior not in line with the project’s code of conduct, you will be ineligible to participate. This year, the first 70,000 participants who successfully complete the challenge will be eligible to receive a prize.

Read the [participation details](https://hacktoberfest.digitalocean.com/details) to learn how to earn your Hacktoberfest tee or tree reward.

## How to Participate

1. ### Fork the Repo

   Give a start and ⭐ Click on **fork** button in the right corner.It will create a copy of repositiry in your account.

    - Check here [How to fork](https://docs.github.com/en/github/getting-started-with-github/fork-a-repo)
    - Image:
    
      <img align="centre" src="https://github.com/BlankCoders/GoogleKickStart2020_Solutions/blob/master/assets/Fork.JPG" alt="fork">

2. ### Clone the Repo

   You can **clone** your repository in your local pc with use of **[GitHub Desktop](https://desktop.github.com/)** application or for your [Terminal/bash](https://git-scm.com/downloads).

   For **Terminal** -

   ```bash
   git clone <url_name>
   ```

   - [Cloning the Repository](https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/cloning-a-repository)
   - Image:
   
      <img src="https://github.com/BlankCoders/GoogleKickStart2020_Solutions/blob/master/assets/Save1.JPG" alt="clone">
      <br>
      <img src="https://github.com/BlankCoders/GoogleKickStart2020_Solutions/blob/master/assets/Save2.JPG" alt="clone">
      
3. ### Upload your Code or Change and Push it

    Make what change you want to make in Repo. It can be spelling mistake, code correction or anything.

    You can also upload your program to respective folder. It can be anything "Hello world program", "Rock Paper Scissors",etc.

    `All Repository are open for contributions.`
    
    <img src="https://github.com/BlankCoders/GoogleKickStart2020_Solutions/blob/master/assets/commands.JPG" alt="clone">
    
     #### After doing necessary edits run commands:
     
      - `git add .`
         - This command updates the index using the current content found in the working tree, to prepare the content staged for the next commit. It typically adds the current content of existing paths as a whole, but with some options it can also be used to add content with only part of the changes made to the working tree files applied, or remove paths that do not exist in the working tree anymore.

         - The "index" holds a snapshot of the content of the working tree, and it is this snapshot that is taken as the contents of the next commit. Thus after making any changes to the working tree, and before running the commit command, you must use the add command to add any new or modified files to the index.

         - This command can be performed multiple times before a commit. It only adds the content of the specified file(s) at the time the add command is run; if you want subsequent changes included in the next commit, then you must run git add again to add the new content to the index.

         - The git status command can be used to obtain a summary of which files have changes that are staged for the next commit.

         - The git add command will not add ignored files by default. If any ignored files were explicitly specified on the command line, git add will fail with a list of ignored files. Ignored files reached by directory recursion or filename globbing performed by Git (quote your globs before the shell) will be silently ignored. The git add command can be used to add ignored files with the -f (force) option.
         
      - `git status`
         - Displays paths that have differences between the index file and the current HEAD commit, paths that have differences between the working tree and the index file, and paths in the working tree that are not tracked by Git (and are not ignored by gitignore). The first are what you would commit by running `git commit;` the second and third are what you could commit by running git add before running git commit.
         
      - `git commit -m "<your message>"`   (exclude brackets)
         - Takes the staged snapshot and commits it to the project history. Combined with git add, this defines the basic workflow for all Git users.
         
      - `git remote add origin <url>`  (exclude brackets)
         -  When you clone a repository with git clone , it automatically creates a remote connection called origin pointing back to the cloned repository. This is useful for developers creating a local copy of a central repository, since it provides an easy way to pull upstream changes or publish local commits.
         
      - `git push --force origin master`
         - Updates remote refs using local refs, while sending objects necessary to complete the given refs.

         - You can make interesting things happen to a repository every time you push into it, by setting up hooks there.
         
         - [Push your first code](https://docs.github.com/en/github/importing-your-projects-to-github/adding-an-existing-project-to-github-using-the-command-line)
   
4. ### Make a PR

    <!-- Push it to your repository and Issue a PR(Pull Request) in main repository. -->
    
    #### Now Since you're done with pushing your code. It's time to do that thing for which we are actually waiting & that is `PULL REQUEST` (in short PR).
    
    * Tap `Pull request`
    <img src="https://github.com/BlankCoders/GoogleKickStart2020_Solutions/blob/master/assets/PR.JPG" alt="PR">
    
    * Tap `Create pull request`
    <img src="https://github.com/BlankCoders/GoogleKickStart2020_Solutions/blob/master/assets/PR1.JPG" alt="PR">

    * Write the Title & Description & Tap `Create pull request`
    <img src="https://github.com/BlankCoders/GoogleKickStart2020_Solutions/blob/master/assets/PR2.JPG" alt="PR">
    
    * Pull requests let you tell others about changes you've pushed to a GitHub repository. Once a pull request is sent, interested parties can review the set of changes, discuss potential modifications, and even push follow-up commits if necessary.

5. ### Merge

   Merging is Git's way of putting a forked history back together again. The git merge command lets you take the independent lines of development created by git branch and integrate them into a single branch. Note that all of the commands presented below merge into the current branch.

## :rocket: Voila! You have Contributed to Open-Source 😋.

If you stuck somewhere contact us:
- [blankcoders@gmail.com](mailto:blankcoders@gmail.com)
