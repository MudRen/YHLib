// baicao-jue.c �ٲݾ�
// Edit By Vin On 26/2/2001
// ����ѧ��֪ʶ���ܣ��ﵽ������ʮ�������������Ǻ��ġ�

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage == "medical"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("medical", 1) < 150)
                return notify_fail("��Ļ���ҽ������̫ǳ����"
                                   "�������µİٲݾ���\n");

        if ((int)me->query_skill("yaowang-miaoshu", 1) < 150)
                return notify_fail("���ҩ����������̫ǳ����"
                                   "�������µİٲݾ���\n");

        if ((int)me->query_skill("medical", 1) < (int)me->query_skill("baicao-jue", 1))
                return notify_fail("��Ļ���ҽ��ˮƽ���ޣ���"
                                   "�����ո���µİٲݾ���\n");

        if ((int)me->query_skill("yaowang-miaoshu", 1) < (int)me->query_skill("baicao-jue", 1))
                return notify_fail("���ҩ������ˮƽ���ޣ���"
                                   "�����ո���µİٲݾ���\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("�ٲݾ�ֻ��ͨ��ѧϰ��ó�����\n");
}
