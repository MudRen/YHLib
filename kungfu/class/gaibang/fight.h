// fight.h
// ؤ������

int accept_object(object ob, object obj)
{
        object me = this_object();

        mapping my_fam = me->query("family");
        mapping ob_fam = ob->query("family");

        if (obj->query("id") != "qingzhu ling")
        {
                command("say ɶ���գ������Ը����Űɡ�");
                return 0;
        }

        if (! ob_fam || ob_fam["family_name"] != "ؤ��")
        {
                command("say ���Ǵ���������������");
                return 0;
        }

        if (ob->query("combat_exp") < 10000)
        {
                command("say ������ˮƽ������ô����������");
                return 0;
        }

        if (ob->query_temp("have_cloth") && present("po bu", ob))
        {
                command("say �㲻���Ѿ����Ʋ�ô����ȥ�Ҽ��ϰɡ�");
                return 0;
        }

        if ((ob->query("family/beggarlvl") == 0
           && ob->query("combat_exp") <= 10000)
           || (ob->query("family/beggarlvl") == 1
           && ob->query("combat_exp") <= 20000)
           || (ob->query("family/beggarlvl") == 2
           && ob->query("combat_exp") <= 50000)
           || (ob->query("family/beggarlvl") == 3
           && ob->query("combat_exp") <= 100000)
           || (ob->query("family/beggarlvl") == 4
           && ob->query("combat_exp") <= 200000)
           || (ob->query("family/beggarlvl") == 5
           && ob->query("combat_exp") <= 300000)
           || (ob->query("family/beggarlvl") == 6
           && ob->query("combat_exp") <= 500000)
           || (ob->query("family/beggarlvl") >= 7
           && ob->query("combat_exp") <= 800000))
        {
             command("say �����ǵ�ŧˮ���ҿ������˰ɡ�");
             return 0;
        }

        if ((ob->query("family/beggarlvl") == 0
           && me->query("title") == "ؤ��һ������")
           || (ob->query("family/beggarlvl") == 1
           && me->query("title") == "ؤ���������")
           || (ob->query("family/beggarlvl") == 2
           && me->query("title") == "ؤ����������")
           || (ob->query("family/beggarlvl") == 3
           && me->query("title") == "ؤ���Ĵ�����")
           || (ob->query("family/beggarlvl") == 4
           && me->query("title") == "ؤ���������")
           || (ob->query("family/beggarlvl") == 5
           && me->query("title") == "ؤ����������")
           || (ob->query("family/beggarlvl") == 6
           && me->query("title") == "ؤ���ߴ�����")
           || (ob->query("family/beggarlvl") == 7
           && me->query("title") == "ؤ��˴�����")
           || (ob->query("family/beggarlvl") == 8
           && me->query("title") == "ؤ��Ŵ�����"))
        {
                ob->set_temp("fight_ok", me->query("id"));
                command("say �ðɡ���Ȼ����������ǾͿ���������ˡ�");
                destruct(obj);
                return 1;
        }

        command("hmm");
        command("say �㵽�׶���������ؤ�������Ĺ�أ�");
        return 0;
}

int accept_fight(object ob)
{
        if (query_competitor() == ob)
                return 1;

        if (is_fighting())
        {
                command("say ��Ȼᣬ���Ұ���ǰ������һ�ŵ���˵��");
                return 0;
        }

        if (query("qi") < query("eff_qi") * 2 / 3
           || query("jing") < query("eff_jing") * 2 / 3
           || query("neili") < query("max_neili") * 2 / 3)
        {
                command("say �������е�ƣ�룬����Ъ�����˵��");
                return 0;
        }

        if (ob->query("family/family_name") != query("family/family_name"))
        {
                command("say ���ˣ��ҿ�û��Ȥ���㶯�֡�");
                return 0;
        }

        if (ob->query_temp("fight_ok") != query("id"))
        {
                command("say ��ȥ�����Ҫ���������������ҡ�");
                return 0;
        }

        ob->delete_temp("fight_ok");

        command("nod");
        command("say ��������һ��������֣������㾿����ɶˮƽ��");
        competition_with(ob);
        return 1;
}

void lost()
{
        object me, ob;

        me = query_competitor();
        me->set_temp("newtitle", query("title"));
        me->set_temp("have_cloth", 1);

        ob = new("/d/gaibang/npc/obj/po-bu");
        ob->set("owner", me->name(1));
        ob->set("from", this_object()->name(1));
        ob->move(this_object());

        command("say ��������������Ȼ��ʤ�����ң�����Ʋ�����ȥ�ɡ�");
        command("give po bu to " + me->query("id"));
        ::lost();
}

void win()
{
        object me = query_competitor();

        if (! objectp(me))
        {
                command("heihei");
                return;
        }
        command("say �������ˮƽҲ����������ȥ���������ɡ�");
        ::win();
}

