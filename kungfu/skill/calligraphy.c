// calligraphy.c

inherit SKILL;

string type() { return "technic"; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
        if ((int)me->query_skill("literate", 1) < 100)
                return notify_fail("��������д�ֶ�ûѧ�ã���̸ʲô�鷨������\n");

        if ((int)me->query_skill("literate", 1) < (int)me->query_skill("calligraphy", 1))
                return notify_fail("��Ķ���д��ˮƽ���ޣ��޷����ո���µ��鷨��\n");

        return 1;

}
