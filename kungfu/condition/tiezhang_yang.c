#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "tiezhang_yang"; }

string chinese_name() { return "���ƴ�����"; }

string update_msg_others()
{
        return RED "ֻ��$N" RED "�ƺ�һ����˫Ŀ͹�������������˿��Ѫ��\n" NOR;
}

string update_msg_self()
{
        return RED "��ֻ�����ﴦ�����٣�������ǧ�����һ���������ڡ�\n" NOR;
}

