// xiakedao ʯ��

int do_study(string arg)
{
        object me;
        int lvl;

        if (arg != "wall")
                return notify_fail("�����о�ʲô��\n");

        me = this_player();
        if (me->query("combat_exp") < 500000)
        {
                write("�㿴�˰��죬ֻ���Լ�ʵս����̫ǳ�����޷���������ĸ���֪ʶ��\n");
                return 1;
        }

        if (me->is_busy())
        {
                write("��������æ��û���о������ʫ�䡣\n");
                return 1;
        }

        me->receive_damage("jing", 15);
        me->start_busy(1);

        lvl = me->query_skill("literate", 1);
        if (lvl >= 200)
                write("�㿴�˰��죬��������ʫд�ĺܺã������ƺ�ûʲô�ر�֮����\n");
        else
        if (lvl >= 100)
                write("������������ʫ����Ԣ�⣬���ɵľ��Ŀ�˼��\n");
        else
        if (lvl >= 1)
                write("�����а��룺�ⶨ��ǰ���������µ��ؼ�����Щ�ʾ��Ҫ�ú÷�����\n");
        else
        if (random(2))
        {
                write("����������ıʻ�����������ϰ���书������������������ᡣ\n");
                if (me->query("experience") < me->query_experience_limit())
                        me->add("experience", 1);
        } else
                write("��Ǳ����ĥ����ıʻ���ȫȻû��������ʲô���塣\n");

	return 1;
}

void init()
{
        add_action("do_study", "think");
        add_action("do_study", "study");
}
