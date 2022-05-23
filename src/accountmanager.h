// Manages, authenticates reddit accounts
// SPDX-FileCopyrightText: 2022 Arnav Rawat <email>
// SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL

#pragma once
#include <QObject>

#include <iostream>

std::ostream& operator<<(std::ostream& lhs, const QString& rhs);


class AccountManager : QObject
{
public:
    AccountManager();
Q_SLOTS
    void AddAuthToken(const QString& token);
};
