/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Nathan Osman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <qmdnsengine/record.h>

#include "record_p.h"

using namespace QMdnsEngine;

RecordPrivate::RecordPrivate()
    : type(0),
      flushCache(false),
      ttl(0),
      priority(0),
      weight(0),
      port(0)
{
}

Record::Record()
    : d(new RecordPrivate)
{
}

Record::Record(const Record &other)
    : d(new RecordPrivate)
{
    *this = other;
}

Record &Record::operator=(const Record &other)
{
    *d = *other.d;
}

Record::~Record()
{
    delete d;
}

QByteArray Record::name() const
{
    return d->name;
}

void Record::setName(const QByteArray &name)
{
    d->name = name;
}

quint16 Record::type() const
{
    return d->type;
}

void Record::setType(quint16 type)
{
    d->type = type;
}

bool Record::flushCache() const
{
    return d->flushCache;
}

void Record::setFlushCache(bool flushCache)
{
    d->flushCache = flushCache;
}

quint32 Record::ttl() const
{
    return d->ttl;
}

void Record::setTtl(quint32 ttl)
{
    d->ttl = ttl;
}

QHostAddress Record::address() const
{
    return d->address;
}

void Record::setAddress(const QHostAddress &address)
{
    d->address = address;
}

QByteArray Record::target() const
{
    return d->target;
}

void Record::setTarget(const QByteArray &target)
{
    d->target = target;
}

QByteArray Record::nextDomainName() const
{
    return d->nextDomainName;
}

void Record::setNextDomainName(const QByteArray &nextDomainName)
{
    d->nextDomainName = nextDomainName;
}

quint16 Record::priority() const
{
    return d->priority;
}
void Record::setPriority(quint16 priority)
{
    d->priority = priority;
}

quint16 Record::weight() const
{
    return d->weight;
}
void Record::setWeight(quint16 weight)
{
    d->weight = weight;
}

quint16 Record::port() const
{
    return d->port;
}

void Record::setPort(quint16 port)
{
    d->port = port;
}

QMap<QByteArray, QByteArray> Record::attributes() const
{
    return d->attributes;
}

void Record::addAttribute(const QByteArray &key, const QByteArray &value)
{
    d->attributes.insert(key, value);
}