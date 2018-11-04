// xun.c

int exert(object me, object target)
{
        object where;

        if (! me->query("can_perform/wiz_test"))
                return notify_fail("����ѧ���ڹ���û�����ֹ��ܡ�\n");

        if (! me->query("quest/id"))
                return notify_fail("����ѧ���ڹ���û�����ֹ��ܡ�\n");

        target = find_player(me->query("quest/id"));

        if (! target)
                target = find_living(me->query("quest/id"));

        if (! target)
                target = find_object(me->query("quest/id"));

        if (! target)
                return notify_fail("û���ҵ�������\n");

        where = environment(target);

        if (! where)
                return notify_fail("����˲�֪��������Ү��\n");

        if (target->query("place")
           && (target->query("place") == "����"
           || target->query("place") == "��Զ�ĵط�"))
                target->move("/d/foshan/street3");

        write(sprintf("%s(%s)������%s(%s).\n",
                (string)target->name(1),
                (string)target->query("id"),
                (string)where->short(),
                (string)file_name(where)));
        
        return 1;
}

