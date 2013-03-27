/*
 * This file is part of LibKGAPI library
 *
 * Copyright (C) 2013  Daniel Vrátil <dvratil@redhat.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef KGAPI2_DRIVEFILECREATEJOB_H
#define KGAPI2_DRIVEFILECREATEJOB_H

#include <libkgapi2/drive/fileabstractuploadjob.h>
#include <libkgapi2/libkgapi2_export.h>

namespace KGAPI2
{

class LIBKGAPI2_EXPORT DriveFileCreateJob : public KGAPI2::DriveFileAbstractUploadJob
{
    Q_OBJECT

  public:
    explicit DriveFileCreateJob(const QString &filePath,
                                const AccountPtr &account, QObject *parent = 0);
    explicit DriveFileCreateJob(const QString &filePath,
                                const DriveFilePtr &metaData,
                                const AccountPtr &account, QObject *parent = 0);
    explicit DriveFileCreateJob(const QStringList &filePaths,
                                const AccountPtr &account, QObject *parent = 0);
    explicit DriveFileCreateJob(const QMap< QString /* filepath */, DriveFilePtr /* metadata */ > &files,
                                const AccountPtr &account, QObject *parent = 0);
    virtual ~DriveFileCreateJob();

  protected:
    virtual QNetworkReply *dispatch(QNetworkAccessManager *accessManager,
                                    const QNetworkRequest &request,
                                    const QByteArray &data);

    virtual QUrl createUrl(const QString &filePath,
                           const DriveFilePtr &metaData);

  private:
    class Private;
    Private * const d;
    friend class Private;

};

} // namespace KGAPI2

#endif // KGAPI2_DRIVEFILECREATEJOB_H
