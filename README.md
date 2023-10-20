<h1>Push Swap</h1>

<h2>Overview</h2>
"Push swap" is a data sorting tool that operates on two stacks using a limited set of instructions. The goal is to sort 500 numbers with less than 5500 moves.
<h2>How To Use</h2>
<ol>
  <li>Clone the repository:</li>
  <pre><code>git clone https://github.com/recozzi/push_swap_42.git</code></pre>
  <li>Move to the project's directory:</li>
  <pre><code>cd push_swap</code></pre>
  <li>Compile the project with Makefile rule:</li>
  <pre><code>make</code></pre>
  <li>To compile the bonus part of the code, use the following command:</li>
  <pre><code>make bonus</code></pre>
  <li>Now you are ready to use push_swap.</li>
  <p>Pass a list of integers at your choice as arguments:</p>
  <pre><code>./push_swap 49 5 88 1 3 24 200</code></pre>
  <p>This will print a list of instructions that will sort the integers. You can verify this by running the checker program:</p>
  <pre><code>./push_swap 49 5 88 1 3 24 200 | ./checker 49 5 88 1 3 24 200</code></pre>
  <p>The checker program will read instructions from standard input. If stack A is sorted and stack B is empty, the checker will print "OK". Otherwise, it will print "KO".</p>
</ol>
<h2>Info</h2>
For more information about this project, please read the subject file <a href="https://github.com/recozzi/push_swap_42/blob/main/en.subject.pdf">here</a>.
<h2>Licence</h2>
See <a href="https://github.com/recozzi/push_swap_42/blob/main/LICENSE">License</a>.
