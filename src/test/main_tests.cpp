// Copyright (c) 2014 The Bitcoin Core developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers 
// Copyright (c) 2018 The Pandora developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "primitives/transaction.h"
#include "main.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(main_tests)

CAmount nMoneySupplyPoWEnd = 30000000 * COIN;

BOOST_AUTO_TEST_CASE(subsidy_limit_test)
{
    CAmount nSum = 0;
    for (int nHeight = 0; nHeight < 1; nHeight += 1) {
        /* premine in block 1 */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 100000 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 1; nHeight < 2000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 1 * COIN);
        nSum += nSubsidy;
    }
    for (int nHeight = 2000; nHeight < 40000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 2 * COIN);
        nSum += nSubsidy;
    }
    for (int nHeight = 40000; nHeight < 60000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 10 * COIN);
        nSum += nSubsidy;

    }
    for (int nHeight = 60000; nHeight < 80000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 7 * COIN);
        nSum += nSubsidy;

    }
	    for (int nHeight = 80000; nHeight < 1000000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 5 * COIN);
        nSum += nSubsidy;

    }
	BOOST_CHECK(nSum > 0 && nSum <= nMoneySupplyPoWEnd);
}

BOOST_AUTO_TEST_SUITE_END()
