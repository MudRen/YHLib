#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit "/inherit/condition/damo";

string name() { return "damo_shangshen"; }

string chinese_name() { return "����֮��"; }

string update_msg_others()
{
        return HIM "$N" HIM "ҡͷ���ԣ����۾����������ˣ�����"
               "ȥ����֮����\n" NOR;
}

string update_msg_self()
{
        return HIR "ֻ�����Լ����񲻼ã�ƣ���������������ܵ���"
               "Ħ���񽣵ĸ��š�\n" NOR;
}

string die_msg_others()
{
        return HIR "$N" HIR "���������뼸�������������£�����"
               "Ҳû�а�㶯����\n" NOR;
}

string die_reason()
{
        return "����˥��������";
}

int jing_damage(object me, mapping cnd)
{
        int d;

        d = cnd["level"];

        if (d > 300 )
                d = 100 + (d - 300) / 12;
        else
        if (d > 60)
                d = 60 + (d - 60 ) / 6;
        d /= 3;
        if (d < 10) d = 10;

        return d / 2 + random(d);
}
