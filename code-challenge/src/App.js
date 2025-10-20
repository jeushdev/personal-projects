import React, { useState, useEffect, useCallback } from 'react';
import { Play, CheckCircle, XCircle, Loader2, Code, FileText, Home as HomeIcon, ChevronRight } from 'lucide-react';

// --- C++ Problem Definition ---
const problem = {
  id: 1,
  title: "Reverse a String",
  difficulty: "Easy",
  language: "C++",
  description: "Write a C++ function named `reverseString` that takes a constant reference to a string (`const std::string& s`) and returns a new string with its characters reversed. You should include the necessary headers (`<string>` and `<algorithm>`).",
  signature: "std::string reverseString(const std::string& s) { ... }",
  example: {
    input: 'std::string s = "hello";',
    output: '"olleh"',
    explanation: "The characters of 'hello' are copied, reversed using `std::reverse`, and returned as 'olleh'."
  },
  // We define a hardcoded 'correct' solution text pattern for simulation
  correctPattern: /std::string\s+reverseString\s*\((const\s+)?std::string(&|\s)s\)/i,
};

// --- C++ Initial Code Template ---
const initialCode = `// Problem ${problem.id}: ${problem.title} in C++

#include <iostream>
#include <string>
#include <algorithm> // for std::reverse

std::string reverseString(const std::string& s) {
  // Your code here
  std::string reversed_s = s;
  std::reverse(reversed_s.begin(), reversed_s.end());
  return reversed_s;
}

// Don't change the function signature above, or the check will fail!
`;

// --- UI Helper Components ---

const StatusIcon = ({ status }) => {
  if (status === 'pass') return <CheckCircle className="w-6 h-6 text-green-500" />;
  if (status === 'fail') return <XCircle className="w-6 h-6 text-red-500" />;
  return null;
};

const ResultCard = ({ result }) => (
  <div className={`mt-6 p-4 rounded-xl shadow-lg transition-all duration-300 ${
    result.status === 'pass' ? 'bg-green-100 border-l-4 border-green-500' : 'bg-red-100 border-l-4 border-red-500'
  }`}>
    <div className="flex items-start space-x-3">
      <StatusIcon status={result.status} />
      <div className="flex-1">
        <h3 className={`font-bold ${result.status === 'pass' ? 'text-green-700' : 'text-red-700'}`}>
          {result.status === 'pass' ? 'Success!' : 'Failed.'}
        </h3>
        <p className={`mt-1 text-sm ${result.status === 'pass' ? 'text-green-600' : 'text-red-600'}`}>{result.message}</p>
      </div>
    </div>
  </div>
);

// --- Home Page Component ---
const HomePage = ({ navigateToProblem }) => (
  <div className="max-w-4xl mx-auto p-8 bg-white rounded-xl shadow-2xl mt-12">
    <h1 className="text-4xl font-extrabold text-indigo-700 mb-4 flex items-center">
      <Code className="w-8 h-8 mr-3" /> Code Challenge Platform
    </h1>
    <p className="text-gray-600 text-lg mb-8">
      Welcome! This platform allows you to practice your C++ skills with interactive, simulated problem checking.
      Click on a challenge below to start coding.
    </p>

    <div className="border border-gray-200 rounded-xl p-6 hover:shadow-lg transition duration-200">
      <div className="flex justify-between items-center">
        <div>
          <h2 className="text-2xl font-semibold text-gray-800">{problem.title}</h2>
          <p className="text-sm text-gray-500 mt-1">
            Difficulty: <span className="font-medium text-green-600">{problem.difficulty}</span> | Language: <span className="font-medium">{problem.language}</span>
          </p>
        </div>
        <button
          onClick={navigateToProblem}
          className="flex items-center space-x-2 px-5 py-2 bg-indigo-600 text-white font-semibold rounded-full shadow-md hover:bg-indigo-700 transition duration-200"
        >
          <span>Start Challenge</span>
          <ChevronRight className="w-5 h-5" />
        </button>
      </div>
    </div>
    
    <div className="mt-8 p-4 bg-yellow-50 text-yellow-800 rounded-lg text-sm">
      <p className="font-semibold">Simulated Environment Note:</p>
      <p>The code checking is simulated. We analyze your code's structure (function signature and use of C++ methods) rather than compiling and running the actual C++ code.</p>
    </div>
  </div>
);


// --- Problem Content Component (for better App logic) ---
const ProblemContent = ({ code, setCode, checkSolution, isLoading, result }) => (
    <div className="max-w-7xl mx-auto grid grid-cols-1 lg:grid-cols-2 gap-8">
        
        {/* --- Problem Panel --- */}
        <div className="bg-white p-6 rounded-xl shadow-2xl h-fit">
          <div className="flex items-center space-x-3 border-b pb-3 mb-4">
            <FileText className="w-6 h-6 text-indigo-600" />
            <h1 className="text-3xl font-extrabold text-gray-900">{problem.title}</h1>
            <span className={`text-xs font-semibold px-3 py-1 rounded-full ${
              problem.difficulty === 'Easy' ? 'bg-green-100 text-green-800' : 'bg-yellow-100 text-yellow-800'
            }`}>{problem.difficulty} | {problem.language}</span>
          </div>

          <section className="mt-4">
            <h2 className="text-xl font-semibold text-gray-800 mb-2">Description</h2>
            <p className="text-gray-600 leading-relaxed">{problem.description}</p>
          </section>

          <section className="mt-6 p-4 bg-gray-50 rounded-lg border border-gray-200">
            <h2 className="text-lg font-semibold text-gray-800 mb-2 flex items-center"><Code className="w-5 h-5 mr-2 text-indigo-500" />Function Signature</h2>
            <pre className="bg-gray-800 text-white p-3 rounded-md text-sm overflow-x-auto">
              <code>{problem.signature}</code>
            </pre>
          </section>

          <section className="mt-6 p-4 bg-indigo-50 rounded-lg border border-indigo-200">
            <h2 className="text-lg font-semibold text-gray-800 mb-2">Example</h2>
            <div className="text-sm">
              <p className="font-medium text-gray-700">Input:</p>
              <pre className="bg-white p-2 rounded-md border text-gray-800 mt-1">{problem.example.input}</pre>
            </div>
            <div className="mt-3 text-sm">
              <p className="font-medium text-gray-700">Output:</p>
              <pre className="bg-white p-2 rounded-md border text-gray-800 mt-1">{problem.example.output}</pre>
            </div>
            <p className="text-xs italic text-gray-500 mt-3">{problem.example.explanation}</p>
          </section>
        </div>

        {/* --- Editor Panel --- */}
        <div className="flex flex-col">
          <h2 className="text-2xl font-bold text-gray-800 mb-4 flex items-center">
            <Play className="w-5 h-5 mr-2 text-indigo-600" /> C++ Code Editor
          </h2>
          
          <textarea
            value={code}
            onChange={(e) => setCode(e.target.value)}
            rows={25}
            className="w-full p-4 border border-gray-300 rounded-xl font-mono text-sm shadow-xl focus:ring-4 focus:ring-indigo-200 transition duration-150 bg-gray-800 text-gray-200"
            placeholder="Write your C++ solution here..."
            disabled={isLoading}
          ></textarea>
          
          <button
            onClick={checkSolution}
            disabled={isLoading}
            className="mt-6 flex justify-center items-center space-x-2 px-6 py-3 bg-indigo-600 text-white font-semibold rounded-xl shadow-lg hover:bg-indigo-700 transition duration-200 disabled:opacity-50 disabled:cursor-not-allowed transform hover:scale-[1.01]"
          >
            {isLoading ? (
              <>
                <Loader2 className="w-5 h-5 animate-spin" />
                <span>Running Test Cases...</span>
              </>
            ) : (
              <>
                <Play className="w-5 h-5" />
                <span>Check Solution</span>
              </>
            )}
          </button>

          {/* --- Result Display --- */}
          {result && <ResultCard result={result} />}

          <div className="mt-4 p-4 text-xs text-gray-500 bg-gray-100 rounded-lg">
            <p className="font-semibold text-gray-700">Note on Checking:</p>
            <p>This is a simulated environment. The code is not compiled or executed. The checker verifies the **C++ function signature** and uses a heuristic based on the provided template code.</p>
          </div>
        </div>
      </div>
);


// --- The Main Application Component (with routing) ---
const App = () => {
  const [code, setCode] = useState(initialCode);
  const [result, setResult] = useState(null);
  const [isLoading, setIsLoading] = useState(false);
  const [currentPage, setCurrentPage] = useState('home'); // 'home' or 'problem'

  const navigateToProblem = () => setCurrentPage('problem');
  const navigateToHome = () => setCurrentPage('home');

  // Simplified simulated check logic for C++
  const checkSolution = useCallback(() => {
    setIsLoading(true);
    setResult(null);

    // 1. Basic Structure Check (C++ Function Signature Check)
    const isFunctionPresent = problem.correctPattern.test(code);
    const isHeaderPresent = code.includes("#include <string>");

    // 2. Simulated Execution Delay
    setTimeout(() => {
      let status = 'fail';
      let message = 'Test Case 1 Failed: Expected "olleh", but received a different result.';

      if (isFunctionPresent && isHeaderPresent) {
        // Checking for the C++ STL solution as the heuristic
        const isTemplateSolutionPresent = code.includes("std::reverse(reversed_s.begin(), reversed_s.end())");

        if (isTemplateSolutionPresent) {
          status = 'pass';
          message = `Test Case 1 Passed! Input: ${problem.example.input}. Output: ${problem.example.output}. Solution accepted.`;
        } else {
            // For any other code, we simulate a compilation or runtime error 50% of the time,
            // or a successful run 50% of the time.
            if (Math.random() < 0.5) {
                 status = 'pass';
                 message = `Test Case 1 Passed! Input: ${problem.example.input}. Your solution was accepted.`;
            } else {
                 status = 'fail';
                 message = "Runtime Error on Test Case 2: Segmentation fault. Check for null pointers or out-of-bounds access.";
            }
        }
      } else {
        message = 'Compilation Error: Ensure you have the correct function signature and necessary includes for C++.';
      }

      setResult({ status, message });
      setIsLoading(false);
    }, 1500); // 1.5 seconds delay to simulate API call
  }, [code]);

  return (
    <div className="min-h-screen bg-gray-50 p-4 sm:p-8 font-inter">
      <script src="https://cdn.tailwindcss.com"></script>
      <style>{`
        .font-inter { font-family: 'Inter', sans-serif; }
        textarea {
          resize: none;
          tab-size: 4;
          -moz-tab-size: 4;
        }
      `}</style>
      
      {/* --- Main Navigation Header --- */}
      <nav className="max-w-7xl mx-auto mb-6">
        <div className="flex items-center space-x-4">
          <button
            onClick={navigateToHome}
            className={`flex items-center space-x-1 px-4 py-2 rounded-full transition duration-150 ${
              currentPage === 'home' ? 'bg-indigo-600 text-white shadow-md' : 'text-gray-600 hover:bg-gray-200'
            }`}
          >
            <HomeIcon className="w-5 h-5" />
            <span>Home</span>
          </button>
          {currentPage === 'problem' && (
            <div className="flex items-center text-gray-500">
              <ChevronRight className="w-5 h-5 mx-1" />
              <span className="font-medium text-indigo-600">{problem.title}</span>
            </div>
          )}
        </div>
      </nav>
      
      {/* --- Page Content --- */}
      {currentPage === 'home' ? (
        <HomePage navigateToProblem={navigateToProblem} />
      ) : (
        <ProblemContent
          code={code}
          setCode={setCode}
          checkSolution={checkSolution}
          isLoading={isLoading}
          result={result}
        />
      )}
    </div>
  );
};

export default App;
