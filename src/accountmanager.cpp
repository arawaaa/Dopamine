// SPDX-FileCopyrightText: 2022 Arnav Rawat <email>
// SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL

#include "accountmanager.h"

std::ostream& operator<<(std::ostream& lhs, const QString& rhs) {
    return lhs << rhs.toStdString();
}
AccountManager::AccountManager()
{

}

void AccountManager::AddAuthToken(const QString& token)
{
    std::cout << token << std::endl;
}
