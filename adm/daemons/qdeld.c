
// created by Rcwiz
#pragma optimize
#pragma save_binary

inherit F_DBASE;

#include <ansi.h>

public int qdel();

void create()
{
        seteuid(ROOT_UID);
        set("name", HIR "�����龫��" NOR);
        set("channel_id", "�����龫��");
        CHANNEL_D->do_channel( this_object(), "sys", "�����龫���Ѿ�������");
        call_out("qdel", 1);
}

public int qdel()
{
        mapping total;
        object *obs;
        object qob;
        int t, i;

	seteuid(getuid());

        total = QUEST_D->query("information");
        if (! mapp(total))
                return 1;

        obs = keys(total);
        obs = filter_array(obs, (: objectp($1) :));

        if (! sizeof(obs))
                return 1;

        foreach(qob  in obs)
        {
               reset_eval_cost();
               
               t = time() - qob->query("start_time");
               if (t >= 1800)
               {
                     qob->cancel_quest();
                     i ++;
               }
               
        }

        CHANNEL_D->do_channel(this_object(), "sys", "ϵͳ�Զ���� " + i + " ������30���ӵ�����");

	return 1;
}

