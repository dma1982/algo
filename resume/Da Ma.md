## Da Ma

He graduated from [Jilin University](http://www.jlu.edu.cn/newjlu/), majoring in grid computing. After graduation, he joined Baidu as R&D engineer of the Ministry of the Web search; subsequently, he transferred to IT department, and committed to the development of workflow software which was used by [Baidu Phoenix Nest](http://e.baidu.com/) and lots of systems. As an IBMer, he is the team lead in China of [Platform Symphony](http://www-03.ibm.com/systems/technicalcomputing/platformcomputing/products/symphony/index.html) CE & L3 team now; continue to contribute his passion to build the best SOA middleware. For the skill, he is a generalist; from C++ to Java, python, php, shell; from Grid/Cloud to Internet, JavaEE, Database, Operation; but his primary skill is to understand the user case quickly and provide suitable solution.

### Interests

Distributed Computing, Grid, Cloud, Project Management (PMP©) 

### Experience

* **Advisory Software Engineer**: Platform Computing, an IBM company (2014/07 ~ Present) at Beijing
* **Team Lead of CE & L3**: Platform Computing, an IBM company (2014/06 ~ Present) at Beijing
* **Team Lead of CE**: Platform Computing, an IBM company (2011/11 ~ 2014/06) at Beijing
* **Software Engineer**: Platform Computing (2010/09 ~ 2011/11) at Beijing
* **Software Engineer**: Baidu (2008/06 ~ 2010/08) at Beijing
* **Researcher**: Platform Computing Grid Technology Research Center at Jilin University (2005/09 ~ 2008/06) at Changchun

### Contacts

**Phone**: N/A; **E-mail**: <mada.jlu@hotmail.com>; **MSN**: <mada.jlu@hotmail.com> 

### Projects

__Multiple Tasks in One Service Instance (MTS)__

In IBM Platform Symphony, it's used to be one process for each running task in compute
host; it's un-convinced for user to share data & computing result. With MTS feature, there
is only one service instance/process for all running tasks from the same job or application.
As the owner of the project, worked on drafting FS, coding and driving the release.

__Tools__: C/C++, GDB, gtest, ACE

__Service Affinity Group (SAG)__

The target of this project is to avoid the overhead when slots transfer between burst jobs,
by allowing different jobs in the same SAG will run on the same service instance where the
data has previously been loaded. As the owner of the project, worked on drafting FS,
coding and driving the release.

__Tools__: C/C++, Java, GDB, gtest, ACE

__Recursive Workload__

Customer's workload pattern is recursive, where a task (parent task) will create another
job (child job) and generate more tasks (child tasks) that are submitted to the child job.
After post-submission processing, parent task will wait for its child tasks to complete.
While it waits, the compute slot is wasted. To increase resource usage, this feature allows
a running task to yield the slot(s), which can be used to run the tasks of its direct
descendants. As local peer, worked with Toronto team on coding, bug fix and driving
release.

__Tools__: C/C++, Java, GDB, gtest, ACE

__R/Python integration__

R & Python are two major integration projects. IBM Platform symphony provides lots of
API for user to submit/create task to the cluster system. The purpose of integration
project is to provide a native API in those programming language. As a project member,
worked on researching, coding & bug fix.

__Tools__: C/C++, R/Python, GDB

__20K cores per application (Multiple-SSM)__

The multi-ssm feature provides better scalability by employing multiple physical
applications to do the real work. Jobs created in logical application are logical jobs, which
internally be mapped to a physical job of one physical application, or physical jobs of
multiple physical applications. Tasks of a logical job will be redirected to the related
physical job(s). Take part in the project as a freshman, worked on coding and unit testing;
and help QA on system test.

__Tools__: C/C++, R/Python, GDB

__Workflow form engine__

In workflow, forms engine is another key module to submit, process and display data. The
purpose of this project is to provide a WYSIWYG system for administrator to manage
workflow forms, a data processing system to handle user's input and a display system to
generate form according to workflow's status and data. As the owner of project, worked
on researching, design and coding.

__Tools__: JEE, MySQL, Shark (workflow), JavaScript/Html/Css

### Education

__Jilin University__
Master, Computer Science and technology 2005 – 2008

1. “Customized Plug-in Modules in Meta-scheduler CSF4 for Life Sciences Applications”, Special Issue on Life Science Grid Computing of New Generation Computing, Vol. 25-4, August 2007
2. “VJM - A Deadlock Free Resource Co-allocation Model for Cross Domain Parallel Jobs”, HPC Asia 2007
3. “VJM - A Deadlock Free Resource Co-allocation Model for Cross Domain Parallel Jobs”, NBCR Summer Institute 2007
4. “VJM - A Deadlock Free Resource Co-allocation Model for Cross Domain
Parallel Jobs”, Journal of Software, pending

__JiLin University__
BS, Computer Science and technology 2001 – 2005

