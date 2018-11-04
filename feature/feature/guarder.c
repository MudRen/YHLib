// guarder.c

#include <ansi.h>

int is_guarder() { return 1; }

int permit_pass(object ob, string dir)
{
        object *inv;
        string fam_name;
        string my_fam;
        string born_fam;
        string msg;
        int i;

        if (! living(this_object()))
                return 1;

        notify_fail("����" + this_object()->name() + "�����������ȥ��\n");
        fam_name = ob->query("family/family_name");
        my_fam   = (string) this_object()->query("family/family_name");
        born_fam = (string) ob->query("born_family");

        if (born_fam == my_fam && fam_name && fam_name != my_fam)
        {
	        if (stringp(msg = this_object()->query("guarder/refuse_home")))
	                message_vision(msg + "\n", this_object(), ob);
                else
                        message_vision(CYN "$N" CYN "����ؿ��˿�$n" CYN "��������"
                                       "��Ȼ�Ѿ�����" + fam_name + CYN "����������"
                                       + my_fam + CYN "��ʲô��\n" NOR,
                                       this_object(), ob);
                return 0;
        }

        if (my_fam != fam_name && my_fam != born_fam)
        {
	        if (stringp(msg = this_object()->query("guarder/refuse_other")))
	                message_vision(msg + "\n", this_object(), ob);
	        else
                        message_vision(CYN "$N" CYN "������ס$n" CYN "�����Բ���"
                                       "��������" + my_fam + CYN "���˲������ڣ�\n"
                                       NOR, this_object(), ob);
                return 0;
        }

        inv = deep_inventory(ob);
        for (i = 0; i < sizeof(inv); i++)
        {
                if (! userp(inv[i])) continue;
                if ((string) inv[i]->query("family/family_name") != fam_name)
                {
	                if (stringp(msg = this_object()->query("guarder/refuse_carry")))
	                        message_vision(msg + "\n", this_object(), ob);
	                else
                                message_vision(CYN "$N" CYN "��$n" CYN "�ȵ����㱳"
                                               "����˭�����������£�\n" NOR,
                                               this_object(), ob);
                        return 0;
                }
        }

        return 1;
}

void kill_enemy(object ob)
{
        mixed result;

        mapping *co;
        string startroom;
        object room;
        object coagent;
        object me;
        int i;
        int flag;

        me = this_object();

        if (! pointerp(co = me->query("coagents")))
                return;

        if (sizeof(co) < 1)
                return;

        if (base_name(environment(me)) != (string)me->query("startroom"))
                return;

        message_vision(random(2) ? HIW "\n$N" HIW "������������ҿ�����æ����\n\n" NOR :
                                   HIW "\n$N" HIW "�ȵ������ã��������������ˣ�\n\n" NOR, me);
        flag = 0;
        for (i = 0; i < sizeof(co); i++)
        {
                if (! mapp(co[i])) continue;

                startroom = co[i]["startroom"];
                if (! objectp(room = find_object(startroom)))
                {
                        result = catch(room = load_object(startroom));
                        if (! objectp(room))
                        {
                                if (wizardp(this_object()))
                                        write(sprintf("��ȡ�������%s\n��׽ѶϢ��%s\n\n",
                                              startroom, result));
                                continue;
                        }
                }

                if (! objectp(coagent = present(co[i]["id"], room)) &&
                    ! objectp(coagent = present(co[i]["id"], environment())) ||
                    ! coagent->is_coagent() ||
                    coagent == this_object())
                        continue;

                flag += (int)coagent->start_help(environment(), me, ob);
        }

        if (! flag)
                message_vision(HIW "���û��һ���˳�����\n" NOR, me);
}

int check_enemy(object ob, string type)
{
        mapping myfam;
        object me;

        me = this_object();
        myfam = ob->query("family");
        if (! mapp(myfam) || ! myfam ||
                myfam["family_name"] != me->query("family/family_name"))
        {
                if (type == "fight")
                {
                        message_vision(CYN "$N" CYN "��$n" CYN "ҡҡͷ����������"
                                       "û�ա�\n\n" NOR, me, ob);
                        return 0;
                } else
                {
                        message_vision(HIR "$N" HIR "��ȵ��������" + RANK_D->query_rude(ob) +
                                       HIR "����ò��ͷ��ˣ���������Ұ��\n" NOR, me, ob);
                        me->kill_ob(ob);
                }
        } else
        switch (type)
        {
        case "hit":
        case "kill":
                message_vision(HIR "$N" HIR "����һ�ɣ��ȵ���" + ob->query("name") +
                               HIR "���������Ҫ�췴��\n" NOR, me, ob);
                me->kill_ob(ob);
                break;

        case "fight":
		if (ob->is_apprentice_of(me))
			message_vision(CYN "$N" CYN "һ��$n" CYN "��ŭ�������"
                                       "�Һú�����ȥ��\n" NOR, me, ob);
		else
                	message_vision(CYN "$N" CYN "��$n" CYN "ҡҡͷ��������"
                                       "��ʦ���Ȼ�ȥ��\n\n" NOR, me, ob);
                return 0;
        }

        return 1;
}
