
string ask_for_join()
{
        object me;
        mapping myfam;
        me = this_player();

        myfam = (mapping)me->query("family");
        if (! myfam || (myfam["family_name"] != "������")) 
                return ("ʩ�����Ҷ���������ԨԴ��ƶ�᲻�Ҹ�����ȡ�");

        if ((string)me->query("class") == "bonze")
                return "�����ӷ𣡳����˲���ڿ����Ѿ������׼����ˡ�";

        if ((string)me->query("gender") != "Ů��")
                return "�����ӷ����գ����գ�ʩ������������ҷ𣬿�ȥ�������ܽ䡣";

        me->set_temp("pending/join_bonze", 1);
        command ("say �����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣");
        return "��ס����Ȼ���˼ң���һ����𣬲��ܻ��ס�";
}

int do_kneel()
{
        object me = this_player();
        string *prename = ({ "��", "��", "��", "��"});
        string name, new_name;

        if (! me->query_temp("pending/join_bonze"))
                return notify_fail("���ڵ��Ϲ���һ�����û�����㡣\n");

        message_vision(HIC "\n$N" HIC "��˫�ֺ�ʮ�����������ع���������\n\n"
                       NOR + CYN "$n" CYN "����$N" CYN "˵�����ðɣ��Ժ����"
                       "�ڱ������аɡ�\n\n" HIY "$n" HIY "������ƣ���$N" HIY
                       "ͷ�������Ħ���˼��£��漴�㽫$N" HIY "��ͷ��������"
                       "ȥ��\n\n" NOR, me, this_object());

        name = me->query("purename");
        if (! name) name = me->query("name");
        new_name = prename[random(sizeof(prename))] + name[0..1];
        command("say �ӽ��Ժ���ķ�������" + new_name + "��");
        command("nod");
        me->set("marks/old_name", name);
        me->delete_temp("pending/join_bonze");
        me->set("name", new_name);
        me->set("class", "bonze");
        me->set("K_record", me->query("PKS") + me->query("MKS"));
        me->set("shen_record", me->query("shen"));
        me->set("shen", 0);

        return 1;
}

void init()
{
        add_action("do_kneel", "kneel");
}
