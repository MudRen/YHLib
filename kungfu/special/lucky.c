// lucky.c ���Ǹ���
// Created by Vin 6/13/2002

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIY "���Ǹ���" NOR; }

int perform(object me, string skill)
{
        return notify_fail("����ܿ�����������ɵ��ĳɹ��ʣ�����Ҫ���á�\n");
}

