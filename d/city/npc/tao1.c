#include <ansi.h>

inherit NPC;

string *rnd_say = ({
        "�����ҹ����ɣ����������µ�����Ӣ�ۡ�������˾�Ȼ����װ����ʶ���ǣ�",
        "Ϊʲ���������С�ӻ�û�����ֺ��Ǹ�С��Ů����һ���ˣ�",
        "��˭���Ը���һЩǮ��ҹè�ӵ�һǧ�����ӻ����ǵ�ʱ�����ٻ�����ɣ�",
        "���뿴������ɵ�ƨ�����ƽɳ����ʽ��",
        "�ɲ����Ը�����������Դ�㣿�´μ��������Ǹ�������ɲ�����ô���ˣ�",
        "���������ͺ¿�����ﲻ�Ƿ����������������",
        "�Ǹ�������ţ����Ϊʲô���������ǣ�",
        "���������ʲô��",
        "�����ͷ�Ӻ���ǧ������һ�����⣡",
        "����Ⱥ����α���ӡ���",
        "������ӯӯ��",
        "�ˡ���",
});

varargs void drool(string msg, string who);

void create()
{
        string name, id;

        set_name("�Ҹ���", ({ "taogen xian", "tao", "gen", "xian", "taogen" }));
        set("title", HIM "�ҹ�����" NOR);
        set("gender", "����");
        set("age", 66);
        set("attitude", "friendly");
        set("combat_exp", 1000000);
        set("env/wimpy", 100);
        set("chat_chance", 30);
        set("chat_msg", ({
                (: command("eat1") :),
                (: command("goeat") :),
                (: command("mapi1") :),
                (: command("drinkcup") :),
                (: command("ugly") :),
                (: command("mapi") :),
                (: command("slogan2") :),
                (: command("zzz") :),
                (: command("lazy") :),
                (: command("slogan") :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
        }) );
        setup();
        if( clonep() ) CHANNEL_D->register_relay_channel("chat");
}

int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "Ү", "");
        msg = replace_string(msg, "��", "");

        if (msg != "")
	{
                add("memory/" + who, ({ msg }));
                return 1;
        } else
		return 0;
}

string make_reply()
{
}

void relay_channel(object ob, string channel, string msg)
{
        string who, phrase;
        who = ob->query("name");

        if (ob == this_object()) return;

        if (add_phrase(who, msg) && random(10) > 4)
                drool(msg, ob->query("name"));
}

void relay_say(object ob, string msg)
{
        string who, phrase;

        if (! userp(ob)) return;
        who = ob->query("name");

        if (ob == this_object()) return;

        if (add_phrase(who, msg) && random(10) > 4)
                drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
        if (! userp(ob)) return;

        switch(verb)
        {
        case "kick":
                if (random(10) < 5 )
		{
                        command("bite");
                        command("say �Ҳ٣���Ƥ������");
                        break;
                } else
                if (random(10) < 5 )
		{
                        command("killair");
                        command("say �����̵ģ���������");
                        break;
                } else
		{
                	command("kick " + ob->query("id"));
                	command("kick1 " + ob->query("id"));
                	command("kick2 " + ob->query("id"));
                        command("say ���̵ģ�������ˬô��");
                        break;
                }
        case "hug":
        case "kiss":
        case "mo":
        case "18mo":
        case "nocloth":

        	if ( (string) ob -> query ("gender") == "����"
                   || (string) ob -> query ("gender") == "����" )
        	{
                	command("say ����ɶ��"+ ob->query("name") + "���Ҿ�ϲ�������������") ;
                	command("say ˭��õ���" + RANK_D->query_rude(ob) + "����Ȼ������֮�á�");
        	} else
        	{
                	command("giggle");
                	command("say �벻��"+ ob->query("name") + "�Զ��Ѷ����������ˡ�");
        	}
        	message_vision(CYN "$N" CYN "ҡ��ҡͷ����$n" CYN "����̾��������������"
                               "�Ǻο��أ�\n" NOR, this_object(), this_player());
        default:
                if (random(10) < 5)
                        command("verb " + ob->query("id"));
                else
                        drool();
        }
}

varargs void drool(string msg, string who)
{
        mapping mem;
        string *ob;

        mem = query("memory");
        if (! mapp(mem)) return;

        if (! msg || ! who)
	{
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }

        if ((strsrch(msg, "Ϊʲô") >= 0) || (strsrch(msg, "��ô") >= 0))
	{
                if (sscanf(msg, "%*sΪʲô%s", msg) == 2) msg = "Ϊʲô" + msg;
                switch(random(8))
		{
                case 0: command("say " + who + "��������������"); break;
                case 1: command("say ���" + msg + "����"); break;
                case 2: command("say ������"); drool(); break;
                case 3: command("say ����������"); break;
                case 4: command("say " + who + "��֪���������Ĵ𰸶���������Ҫô��"); break;
                case 5: command("say " + msg + "��"); break;
                case 6: command("say " + who + "���ܲ���˵���һ�㣿"); break;
                case 7: command("say " + who + "���Ҳ������ʵ�����"); break;
                }
        } else
	if ((strsrch(msg, "��") >= 0)
           || (strsrch(msg, "��") >= 0)
           || (strsrch(msg, "drooler") >= 0)
           || (strsrch(msg, "Drooler") >= 0))
	{
                if (sscanf(msg, "%*s��%s", msg) == 2) msg = "��" + msg;
                msg = replace_string(msg, "��", "��");
                msg = replace_string(msg, "��", "��");

                switch(random(10))
		{
                case 0: command("say " + who + "������˵" + msg + "��");break;
                case 1: command("say ��ȷ��" + msg + "��");     break;
                case 2: command("say " + msg + "������ʲ���ϵ��");     break;
                case 3: command("say �š���" + who + "˵�ú�"); break;
                case 4: command("say " + who + "��Ϊʲ���" + msg + "��������Ȥ��"); break;
                case 5: command("say Ϊʲ������Ϊ" + msg + "��"); break;
                case 6: command("say ���������"); drool(); break;
                case 7: command("say �Ź֣�"); break;
                case 8: command("say ��һ���ɣ�"); break;
                case 9: command("say ��������ܡ���"); break;
                }
        } else
	if ((strsrch(msg, "��") >= 0))
	{
                if (sscanf(msg, "%*s��%s", msg) == 2) msg = "��" + msg;
                msg = replace_string(msg, "��", "��");
                msg = replace_string(msg, "?", "");

                switch(random(8))
		{
                case 0: command("say ����˵" + msg + "��"); break;
                case 1: command("say ��ģ�" + msg + "��");     break;
                case 2: command("say ���" + msg + "�����ܰ���ʲ��æ��");break;
                case 3: command("hmm"); break;
                case 4: command("say ����Ϊ" + msg + "��"); break;
                case 5: command("say ����ͬ��"); break;
                case 6: command("say ��˵�ġ�" + msg + "���Ҳ��ܹ�ͬ"); break;
                case 7: command("say �йء�" + msg + "���Ļ��⵽��Ϊֹ����");;
                }
        } else
	{
                switch(random(20))
		{
                        case 0: command("say Ϊʲ��˵" + msg + "?"); break;
                        case 1: command("say ��" + msg + "����ʲ����˼��"); break;
                        case 2: command("say " + msg + "��"); break;
                        case 3: command("grin"); break;
                        case 4: command("smile"); break;
                        case 5: command("?"); break;
                        case 6: command("say ...."); break;
                        case 7: command("hmm"); break;
                        case 8: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
                        case 9: command("say ������֪��" + msg + "?"); break;
                        case 10: command("say �ո�" + who + "����˵�ˣ�" + msg);
                        case 11: command("say �ҵ�Ȼ֪����" + msg); break;
                        case 12: command("say Ȼ���أ�"); break;
                        case 13: command("say �����"); break;
                        case 14: command("say �Ҳ�������Ϊ��"); break;
                        default:
                                break;
                }
        }
}

void reset()
{
        delete("memory");
}

int accept_object()
{
        return 1;
}

void init()
{
    	object ob;

    	::init();
    	if( interactive(ob = this_player())
           && ! is_fighting())
	{
        	remove_call_out("greeting");
        	call_out("greeting", 1, ob);
    	}
    	add_action("do_dajia", "hit");
    	add_action("do_kill", "kill");
    	add_action("do_dajia", "fight");
}

void greeting(object ob)
{
    	if (! ob || environment(ob) != environment()) return;

        message_vision(CYN "�ҹ��������ȿֺ�س�$N" CYN "�к����������������ֵܺȾƣ�\n"
                       "�Ҹ��ɣ�б��$N" CYN "һ�ۣ�ͻȻ�����������þ�����\n"
                       "��֦���������ӣ����������ӽ���Ҫһ�ߺȾƣ�һ�߿����˰�$N" CYN
                       "�ֳɾſ飡\n"
                       "��Ҷ�����˹�����һ��ץס$N" CYN "���µ����ҵ�һ���ҵ�һ��\n"
                       "�һ��ɺ��Ŷ̹�������һƨ�����£���ƾͺȡ�\n"
                       "��ʵ�ɳ���$N" CYN "������Ƥ������һ�������ó���$N" CYN "ֱð��\n" NOR, ob);
}

int do_dajia()
{
    	object ob;

    	ob = this_player();
    	message_sort(HIR "\n�ҹ�����һӵ���ϣ�������ȭ��$N" HIR "һ�ٳ���$N" HIR
                     "���ڵ��ϣ���У��ҹ���үү����λ��Ӣ���������ҹ���������Ƥ��"
                     "����ʱ��¶��Ц�ݣ�$N" HIR "���۹⣬�Ǹ�����ˣ����ͣͣ����"
                     "�ֱ���ˣ�\n\n" NOR, ob);
    	ob->set("eff_qi", 10);
    	return 1;
}

int do_kill()
{
    	object ob;
    	ob = this_player();
    	message_sort(HIR "\n�ҹ����ɶ�ʱһӵ���ϣ�������ȭ��$N" HIR "��������Ҹ�"
                     "�ɺ��Ҹ��ɣ���֦�ɣ���Ҷ�ɷ�ץ$N" HIR "��֫��ֻ����һ���Һ���"
                     "������Ѫ���࣬�ҹ����ɾ���$N" HIR "������˺����Ƭ���һ��ɺ���"
                     "ʵ�������Աߣ����˶��Ȼ����ˣ�\n\n", ob);
        ob->set_temp("die_reason", "���ҹ�����˺������Ƭ");
    	ob->die();
    	return 1;
}
