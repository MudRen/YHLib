// might.c ����ȭ
// Created by Vin 25/5/2002

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return CYN "����ȭ" NOR; }

int perform(object me, string skill)
{
        return notify_fail("������ܹ�������ļ������ޣ�����Ҫ���á�\n");
}

