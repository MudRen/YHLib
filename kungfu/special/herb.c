// herb.c ����֪ʶ
// Created by Vin 6/13/2002

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIG "����֪ʶ" NOR; }

int perform(object me, string skill)
{
        return notify_fail("����ܿ�ʹ��������Ч�����ո���ҩ�����Ҫ���á�\n");
}

