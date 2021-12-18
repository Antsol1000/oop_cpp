cmake_minimum_required(VERSION 3.20)
project(c___project)

set(CMAKE_CXX_STANDARD 14)

add_executable(c___project src/main.cpp src/coins/currency/Currency.cpp src/coins/currency/Currency.h src/coins/currency/fiat/FiatCurrency.cpp src/coins/currency/fiat/FiatCurrency.h src/coins/currency/crypto/CryptoCurrency.cpp src/coins/currency/crypto/CryptoCurrency.h src/coins/currency/crypto/BlockchainCoin.cpp src/coins/currency/crypto/BlockchainCoin.h src/wallet/Wallet.h src/coins/currency/crypto/StableCoin.cpp src/coins/currency/crypto/StableCoin.h src/coins/currency/crypto/MemeCoin.cpp src/coins/currency/crypto/MemeCoin.h src/coins/coins.h src/coins/trader/Trader.cpp src/coins/trader/Trader.h)
