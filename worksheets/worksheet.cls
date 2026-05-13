\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{../worksheet}[2016/01/01]

\LoadClass[10pt, twoside]{article}

\usepackage{fancyhdr,rotating}

\usepackage{graphicx}
\usepackage{listings}
\usepackage{anysize}
\usepackage{array}
\usepackage{booktabs}
\usepackage{tabu}
\usepackage{makecell}
\usepackage{xcolor, colortbl}
\usepackage{multirow}
\usepackage{verbatim}
\usepackage{fancyvrb}

\marginsize{1.5cm}{1.5cm}{1.5cm}{1.5cm}
\pagenumbering{gobble}

% Title
\newcommand{\mytitle}[1]{\gdef\@mytitle{#1}}

\pagestyle{fancy}
 \let\headrule=\empty
 \let\footrule=\empty
 \chead{{\bfseries \@mytitle}}

\lstset{language=C}

\newcommand{\code}{\texttt}

% Remove indentation
\setlength{\parindent}{0pt}

%% Macro for making answerbox
\newcommand*{\answerbox}[1]
{\vspace*{-0.4cm}\begin{center}\fbox{\begin{minipage}{7in}\vspace*{#1}\hspace*{7in}\end{minipage}}\end{center}}
\newcommand*{\newanswerbox}[2]
{\fbox{\begin{minipage}{#2}\vspace*{#1}\hspace*{#2}\end{minipage}}}


%% New conditional to allow formatting of either solutions or notes.
\newif\ifsolutions % starts out false by default
\newif\ifnotes % starts out false by default

\endinput
