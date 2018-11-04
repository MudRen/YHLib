// fire_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "fire_poison"; }

string chinese_name() { return "���޶���"; }

string update_msg_others()
{
        return HIR "$N" HIR "һ���Һ���ȫ��ȼ����" HIG "����ɫ"
               HIR "�Ļ��档\n" NOR;
}

string update_msg_self()
{
        return HIR "��ֻ��ȫ�������ޱȣ�������ȼ���" HIG "����"
               HIR "ֱ�����衣\n" NOR;
}

string die_msg_others()
{
        return HIR "$N" HIR "���ݵ������ڵ��������˼��£�����û"
               "��㶯���ˡ�\n" NOR;
}

string die_reason()
{
        return "�����޶�����������";
}