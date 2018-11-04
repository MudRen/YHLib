#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int max, pts;

        // ����ȭ���Ӽ�������
        if (me->query("special_skill/might"))
                max = (int)me->query_skill("force") * 2 / 3;
        else
                max = (int)me->query_skill("force") / 2;

	if (! arg || (arg != "none" && arg != "max"
           && arg != "half" && ! sscanf(arg, "%d", pts)))
		return notify_fail("\nָ���ʽ��enforce|jiali <ʹ�����������˵�>"
                                   "|max|half|none \n�������������" HIY +
                                   chinese_number(max) + NOR "�������˵С�\n");

	if (! me->query_skill_mapped("force"))
		return notify_fail("������� enable һ���ڹ���\n");

	if (arg == "none")
		me->delete("jiali");
	else
	{
		if (arg == "max")
			pts = max;

		if (arg == "half")
			pts = max / 2;

		if (pts < 0)
			return notify_fail("��ֻ���� none ��ʾ����������������"
                                           "��ʾÿһ���ü���������\n");

		if (pts > max)
			return notify_fail("�����ֻ����" HIY + chinese_number(max)
                                           + NOR "�������˵С�\n");

		me->set("jiali", pts);
	}
	if (! me->query("jiali"))
		write(HIC "���������ʹ������������\n" NOR);
	else
		write(HIC "�������" HIY + chinese_number(pts) + HIC "�������˵С�\n" NOR);
	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: enforce|jiali <ʹ�����������˵�>|max|half|none

���ָ������ָ��ÿ�λ��е���ʱ��Ҫ�������������˵С����� max
��ʾ�㽫ʹ������޶�ļ��������˵С�half��ʾʹ������޶�һ��
�ļ��������˵С���none���ʾ�㲻��ʹ������������

HELP);
        return 1;
}
