# USA-University-Course-Allotment-System

The project focuses on optimizing the University Course Assignment System within a department, addressing the complex task of assigning courses to faculty members belonging to distinct categories ("x1," "x2," "x3"). Each category has specific course load constraints, and faculty members express preferences through prioritized lists. The challenge is to develop an assignment scheme that maximizes course assignments while adhering to faculty preferences and category-based constraints. Notably, the system allows faculty flexibility in taking multiple courses, and a single course can be assigned to multiple faculty members, with load considerations. The uniqueness of this problem lies in its flexibility, differing from conventional Assignment problems, offering avenues for potential modifications to enhance its applicability.

## Methodology

- We’ll Start by inputting professors and and their priority order 
- We’ll make a bipartite graph of this data with courses being the first set of vertices and  Professors being the second set of vertices rather than an intuitive vice-versa approach.
- We’ll make an algorithm (later) for making a priority order for each course. It can never be 100% optimised, but we’ll try to make it as optimised as possible using algorithms like sorting by a preference score, which could be calculated by<br>
1 -  Professor priority rank of that course/Total priorities of the professor.
- Similarly, We’ll have to make a general preference order of all the Courses (which we’ll do at last).
- Then, we’ll apply the Hungarian Algorithm (Refer to the Prerequisites) with the order Source - Courses - Professors - Sink, with weights between source and all course being 2 (since a course is taught by 2 x ½ professors) and weight between Professors and Sink being the maximum course a prof can take x 2(basically, their category no.). We basically took ½ course as 1 unit to come up with this. 
- We shall generate a warning message if all of the professors’ slots are not filled. It could be a case if courses are much less than the professors. And this is why we did opposite bipartite matching in the second step, because we can not have a course being taught by half a professor and no one is teaching the other half.
- We’ll apply the algorithm 2 times on each course and if the course is impossible to be taken then, we’ll take back the first set of algorithms too.
- A lot of optimizations are possible in this code, which we’ll do after completing this basic structure, ironically which is not at all basic.


## Prerequisites


- **Code Representation of Graphs** ** : https://www.youtube.com/watch?v=bTtm2ky7I3Y
- **DFS**: https://www.youtube.com/watch?v=PMMc4VsIacU
- **Ford-Fulkerson’s Algorithm**: https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
- **Maximum Bipartite Matching**: https://www.geeksforgeeks.org/maximum-bipartite-matching/
- **Maximum Weighted Bipartite Matching**: https://cse.iitkgp.ac.in/~abhij/course/theory/Algo2/Autumn21/slides/5-Weighted-Matching.pdf

** If you are having difficulties understanding the various terminologies in this video, Refer to the lecture slides of Graphs.


## Getting Started

### Installation:

1. **Clone the repository:**
   - Download the GitHub Desktop app from `https://desktop.github.com`.
   - Open GitHub Desktop.
   - Click on "File" in the menu and select "Clone repository."
   - Choose "Your Repositories" and choose USA-University-Course-ALlotment_System.
   - Choose the local path where you want to clone the repository.
   - Click "Clone."

 2. **Navigate to the project directory:**
    - Open the cloned repository in Visual Studio Code or your preferred code editor.

### Usage:

After completing the desired changes in the code, you can proceed with the following steps:

#### Committing Changes:
- Open GitHub Desktop.
- You will see a list of changes you made. Review them.
- In the "Summary" field, enter a brief, descriptive commit message.
- Optionally, provide a more detailed description in the "Description" field.
- Click "Commit to [branch name]."
  
#### Syncing Changes:
Click the "Repository" menu and select "Push origin" to push your committed changes to the GitHub repository.

#### Branching:
To create a new branch, click the "Current Branch" dropdown and choose "New Branch."
Enter a branch name and click "Create Branch."
Make changes on the new branch, commit them, and then push the branch to GitHub.

##### Merging Changes:
After making and committing changes on a branch, switch back to the main branch.
Click the "Repository" menu and select "Merge into current branch."
Choose the branch you want to merge and click "Merge [branch name] into [current branch]."

## Contributing

Your contributions can significantly impact the success of this project. Currently, we are very short on time, so your swift involvement is crucial.

### How to Contribute:

1. **Check the [Issues](../../issues) Tab:**
   - Browse through the existing issues to find tasks that align with your skills and interests.

2. **Select an Issue:**
   - Choose an issue that you'd like to work on or feel free to open a new one if you have identified a specific improvement or bug.

3. **Assign Yourself:**
   - If you decide to work on an issue, please assign yourself to it promptly. Time is of the essence, and this helps avoid duplicate efforts.

4. **Fork the Repository:**
   - Fork this repository to your GitHub account.

5. **Make Changes:**
   - Implement the necessary changes in your forked repository as swiftly as possible.

6. **Create a Pull Request:**
   - Once your changes are ready, submit a pull request to the main repository. Ensure your pull request clearly explains the changes made and addresses the associated issue.

7. **Review and Collaborate:**
   - Participate in the review process promptly by responding to comments or making further improvements based on feedback.

### Suggesting Issues:

1. **Open the [Issues](../../issues) Tab:**
   - Browse through the existing issues to find tasks that align with your skills and interests.
     
2. **Add a Issue**
   - Click "New Issue". And add your issue/suggestion for our code there.

## License

Apache License
Version 2.0, January 2004

Copyright (c) 2023 Team USA - Unnabh, Shrey & Aditya

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at AH-9 337, BITS Goa

Thank you for contributing to the USA University Course Allotment System!

...

