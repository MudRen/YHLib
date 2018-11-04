#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int max, pts;

        // ��ŭ֮�����Ӽ�ŭ����
        if (me->query("special_skill/wrath"))
                max = me->query_max_craze() / 70;
        else
                max = me->query_max_craze() / 100;

        if (max < 1)
                return notify_fail("����Ը񲻺ϣ��޷�ʹ�÷�ŭ������\n");

	if (! arg || (arg != "none" && arg != "max"
           && arg != "half" && ! sscanf(arg, "%d", pts)))
                return notify_fail("\nָ���ʽ��pique|jianu <ʹ�����ɷ�"
                                   "ŭ�˵�> |max|half|none \n���������"
                                   "����" HIG + chinese_number(max) + NOR
                                   "���ŭֵ�˵С�\n");

	if (arg == "none")
		me->delete("jianu");
	else
	{
		if (arg == "max")
			pts = max;

		if (arg == "half")
			pts = max / 2;

		if (pts < 0)
			return notify_fail("��ֻ���� none ��ʾ���÷�ŭ��������"
                                           "��ʾÿһ���ü����ŭֵ��\n");

		if (pts > max)
			return notify_fail("�����ֻ����" HIG + chinese_number(max)
                                           + NOR "���ŭֵ�˵С�\n");

		me->set("jianu", pts);
	}
	if (! me->query("jianu"))
		write(HIC "���������ʹ�÷�ŭֵ�˵С�\n" NOR);
	else
		write(HIR "�������" HIG + chinese_number(pts) +
                      HIR "���ŭֵ�˵С�\n" NOR);
	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: pique|jianu <ʹ�������ŭֵ�˵�>|max|half|none
 
���ָ������ָ��ÿ�λ��е���ʱ�����������ŭ�˺��Է������ʹ
�÷�ŭ�˵У����ڹ����л���һ���ļ��ʿ���ʹ����ŭ��ɱ����ŭ��
ʽ������ max ��ʾ�㽫ʹ������޶�ķ�ŭֵ�˵С�half ��ʾʹ��
����޶�һ��ķ�ŭֵ�˵С���none���ʾ�㲻��ʹ�÷�ŭֵ�˵С�

���ָ���ŭ(berserk)����й(burning)

HELP);
        return 1;
}
