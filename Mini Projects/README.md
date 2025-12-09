🇰🇪 M-PESA C Simulation 📱
This project is a command-line application written in C that simulates the core functionalities of the M-Pesa mobile money transfer service. It provides a menu-driven interface for users to perform common financial transactions like sending money, deposits, withdrawals, and managing balances, loans, and savings.

The simulation uses file I/O to persistently store user data, including PIN, balance, and a transaction history, making the experience dynamic and realistic for a CLI environment.

✨ Features
The simulation includes a wide range of M-Pesa services:

.Send Money: Transfer funds to another number with a calculated transactional cost.

.Withdraw Cash: Withdraw money from a simulated agent, including fees.

.Deposit Amount: Add funds to the M-Pesa account from an agent.

.Lipa na M-Pesa: Includes options for Paybill, Buy Goods and Services, and Pochi la Biashara.

.Balance Checks: Check balances for M-Pesa, Savings, and Loans accounts.

.PIN Management: Option to change the security PIN.

.Mini Statement: Retrieve the last N number of transactions from the history log.

.Loans and Savings:

.Borrow up to Ksh 15,000 in a simulated loan.

.Save funds to a separate Savings account.

.Repay existing loans.

.Withdraw from savings to the main M-Pesa balance.

🛠️ Setup and Installation
1. File Initialization (Crucial)
Since the program relies on reading the latest state from files, you must create these empty files in the same directory as the source code (mpesa_simulation.c):

Filename Purpose Initial Content Recommendation
>pin.txt Stores the current 4-digit PIN.1234
>balance.txt Stores the current M-Pesa balance .5000.00
>loans.txt Stores the outstanding loan amount. 0.00
>savings.txt Stores the current savings balance. 0.00
>transaction.txt Logs all transaction history. (Leave empty)

Prerequisites
to compile and rum the simulation, you need:
1. C compiler (like GCC)


Usage
After running the simulation , the main menu will apear, and you can interact with the ststem by entering coresponding number.

Author
Lawrence Mwangi

License
This project is open source
