
void init()
{
        add_action("do_kneel", "kneel");
}

string ask_for_join()
{
        object me;

        me = this_player();

        if ((string)me->query("class") == "bonze")
                return "���Ѿ��ǳ������ˣ�����������Щʲô��";

        if ((string)me->query("gender") != "����")
                return "���Ǵ���������ֻ����ͽ���㻹���߰ɡ�";

        me->set_temp("pending/join_bonze", 1);

        return "���ã����ã�������������ҷ������(kneel)�ܽ䡣";
}

int do_kneel()
{
        object me = this_player();

        if (! me->query_temp("pending/join_bonze"))
                return 0;

        message_vision(HIC "\n$N" HIC "��˫�ֺ�ʮ�����������ع���������\n\n"
                       NOR + CYN "$n" CYN "����$N" CYN "˵�����ðɣ��Ժ����"
                       "�ڱ������аɡ�\n\n" HIY "$n" HIY "������ƣ���$N" HIY
                       "ͷ�������Ħ���˼��£��漴�㽫$N" HIY "��ͷ��������"
                       "ȥ��\n\n" NOR, me, this_object());

        me->set("class", "bonze");
        me->set("title", "����������");      

        command("nod");
        command("say ��Ȼ���˼ң��͵�һ������ٲ��ܻ��ס�");

        return 1;
}
