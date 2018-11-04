#include <ansi.h>

inherit NPC;
inherit F_DEALER;
inherit F_UNIQUE;

static object *receiver;

object *query_receiver() { return receiver; }

int ask_fee();
int ask_bomb();
int ask_shedu();
int ask_duwan();
int ask_list();
mixed ask_cancel();
int filter_listener(object user);

void create()
{
        set_name("����", ({ "bei chou", "bei", "chou", "xizi" }));
        set("long", @LONG
����һ������Ϸ�Ӵ�����С��ͷ�����ü���
����������һ�����ࡣ˭����֪����ǵ�����
���кųơ����ͱ���Ϸ�ӱ�������������
����֮�£���ȴҲ��������ƽ��η��֮�ˡ�
LONG);
        set("nickname", HIW "��Ϸ��" NOR);
        set("title", HIC "����̩��" NOR);
        set("gender", "����" );
        set("age", 68);
        set("attitude", "friendly");
        set("max_jing", 50000);
        set("max_qi", 50000);
        set("max_jingli", 50000);
        set("jingli", 50000);
        set("max_neili", 50000);
        set("neili", 50000);
        set("jiali", 350);
        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
        set("combat_exp", 12000000);

        set("inquiry", ([
                "name" : "�����Ǳ�����Ҫ������ʲô��",
                "rumor": "�ߣ�����Ϸ���Ҵ�ţ��˭��ҥ���Ҷ��ܲ������",
                "fee"  : (: ask_fee :),
                "�շ�" : (: ask_fee :),
                "bomb" : (: ask_bomb :),
                "ը��" : (: ask_bomb :),
                "�߶�" : (: ask_shedu :),
                "��ҩ" : (: ask_duwan :),
                "�˵�" : (: ask_list :),
                "����" : "�ٺٺ٣��������˭��������Ϣ�Ǹ���ͨ����",
                "����" : "�����Ǹ���ͷû���ѧ�ʣ�����ʲô�������Һ��ˡ�",
                "��ը��"    : (: ask_list :),
                "���ӷɵ�"  : (: ask_list :),
                "����ը��"  : (: ask_list :),
                "���ӵ���"  : (: ask_list :),
                "��ë��"    : (: ask_list :),
                "��ë�ȵ���": (: ask_list :),
                "��Ȫˮ"    : "���ɵ�ը�ˣ�����ƿ���ʣ�",
                "������"  : "��ѧô(idle-force)��Ϸ���ҽ̣�����Ǯ�ġ�",
                "cancel"    : (: ask_cancel :),
        ]));

        set("vendor_goods", ({
                "/clone/gift/feidan",
                "/clone/gift/feimao",
                "/clone/gift/kuangquan",
        }));

        set("chat_chance", 1);
        set("chat_msg",({
                CYN "������������Ϸ����û��ı��£��ͻ������Ϣ����������ʦ��ҥ����Ҳ��֪����\n" NOR,
                CYN "��������һָ�������˰����������Ӿ��ܲ���ҥ�ԣ����������¥�ۡ�\n" NOR,
                CYN "���������е�˵��������㲻�����㣬��������ô��Ϸ���Ҷ�֪����\n" NOR,
        }));

        set_skill("dodge", 500);
        set_skill("unarmed", 500);
        set_skill("force", 500);
        set_skill("parry", 500);
        set_skill("sword", 500);
        set_skill("poison", 500);
        set_skill("medical", 500);
        set_skill("hand", 500);
        set_skill("strike", 500);
        set_skill("staff", 500);
        set_skill("finger", 500);
        set_skill("claw", 500);
        set_skill("blade", 500);
        set_skill("pixie-jian", 500);
        set_skill("literate", 500);
        set_skill("taoism", 500);
        set_skill("buddhism", 500);
        set_skill("jiuyang-shengong", 500);
        set_skill("lingbo-weibu", 500);
        set_skill("qiankun-danuoyi", 500);
        set_skill("xuanming-zhang", 500);
        set_skill("jiuyin-baiguzhao", 500);
        set_skill("dugu-jiujian", 500);
        set_skill("qianzhu-wandushou", 500);
        set_skill("ranmu-daofa", 500);
        set_skill("dagou-bang", 500);
        set_skill("shaolin-yishu", 500);
        set_skill("wudu-qishu", 500);
        set_skill("throwing", 500);
        set_skill("mantian-xing", 500);
        set_skill("idle-force", 500);
        set_skill("sad-strike", 500);

        map_skill("unarmed", "sad-strike");
        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "lingbo-weibu");
        map_skill("parry", "qiankun-danuoyi");
        map_skill("hand", "qianzhu-wandushou");
        map_skill("strike", "xuanming-zhang");
        map_skill("claw", "jiuyin-baiguzhao");
        map_skill("sword", "dugu-jiujian");
        map_skill("blade", "ranmu-daofa");
        map_skill("staff", "dagou-bang");
        map_skill("throwing", "mantian-xing");
        map_skill("poison", "wudu-qishu");
        map_skill("medical", "shaolin-yishu");

        prepare_skill("unarmed", "sad-strike");

        set("chat_chance_combat", 200);
        set("chat_msg_combat", ({
                (: perform_action, "sword.po" :),
                (: perform_action, "blade.zhenyan" :),
                (: perform_action, "blade.huo" :),
                (: perform_action, "staff.wugou" :),
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "unarmed.xiao" :),
                (: perform_action, "parry.nuoyi" :),
                (: perform_action, "dodge.lingbo" :),
                (: perform_action, "throwing.shan" :),
                (: perform_action, "hand.zhugu" :),
                (: perform_action, "strike.wuji" :),
                (: perform_action, "finger.six" :),
                (: perform_action, "finger.zhongheng" :),
                (: perform_action, "claw.zhua" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
                (: exert_function, "heal" :),
                (: exert_function, "dispel" :),
                (: exert_function, "regenerate" :),
        }));

        setup();
        carry_object("d/city/obj/cloth")->wear();

        if (! clonep(this_object()))
        {
                move("/d/city/kedian");
                message_vision(CYN "\n$N" CYN "Ц���������������ˣ�Ϸ�������ˡ�\n"
                               NOR, this_object());
                set("startroom", "/d/city/kedian");
        }
        set_temp("bomb_count", 1);
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

mixed accept_ask(object ob, string topic)
{
        object fob;

        if (topic == ob->query("id"))
        {
                command("laugh " + topic);
                return 1;
        }

        fob = find_player(topic);
        if (! fob || ! ob->visible(fob)) fob = find_living(topic);
        if (! fob || ! ob->visible(fob) || ! environment(fob))
                return;

        if (fob->query("ask_cheap") >= 1)
        {
                ob->set_temp("pending/ask_beichou", topic);
                ob->set_temp("pending/ask_value", 1000);
                message_vision(CYN "$N" CYN "������üͷ����$n" CYN "ҡҡ"
                               "ͷ�������������ȷʵ�����������ѣ�����ʮ"
                               "�����������ˡ�\n" NOR, this_object(), ob);
                return 1;
        } else
        {
                ob->set_temp("pending/ask_beichou", topic);
                ob->set_temp("pending/ask_value", 100000);
                message_vision(CYN "$N" CYN "�ٺټ�Ц��������$n" CYN "С"
                               "������û�����⣬������Ҫʮ���ƽ𣬲���"
                               "�ۣ�\n" NOR, this_object(), ob);
                return 1;
        }
}

int recognize_apprentice(object me, string skill)
{
        if (skill != "idle-force")
        {
                if (me->add_temp("illegal_learn", 1) > 3)
                {
                        command("say ��������ô�������Ǹ��ϲ����Ļ�����");
                        message_vision(HIC "$n�������һ�ţ���$N"
                                       HIC "�߳����⣡\n" NOR,
                                       me, this_object());
                        me->set_temp("illegal_learn", 2);
                        me->move("/d/city/beidajie1");
                        me->unconcious();
                } else
                        command("say ��ֻ�̷����񹦣����������书��");
                return -1;
        }

        message_vision(HIC "$N" HIC "��$n" HIC "��̷����񹦵ľ��ϡ�\n" NOR,
                       me, this_object());

        if (me->query_temp("learned_idle_force"))
        {
                if (me->add_temp("too_many_xue", 1) > 3)
                {
                        command("say �����̵ģ���Ȼ���������ϲ��������£�");
                        message_vision(HIC "$n�������һ�ţ���$N"
                                       HIC "�߳����⣡\n" NOR,
                                       me, this_object());
                        me->set_temp("too_many_xue", 1);
                        me->move("/d/city/beidajie1");
                        me->unconcious();
                } else
                        command("say ���ȰѰ��ղŽ�����������˵�ɣ�");
                return -1;
        }

        command("say �����ˣ���������ּ��@#$%^&%#$#@$%&*&+*^&����");

        if (me->query("potential") < me->query("learned_points") + 10)
        {
                write(HIY "������ϡ���Ϳ��������Ǳ�ܲ����ˡ�\n" NOR);
                return -1;
        }

        if (me->query_skill("idle-force", 1) > 500)
        {
                write(HIW "�����������룬��Щ�Ҷ���������������Ҳ"
                      "��֪����ô���ˡ�\n" NOR);
                return -1;
        }

        me->set_temp("learned_idle_force", 1);
        me->add("learned_points", 10);
        write(HIW "�����������������ã����Ͻ��з�����ϰ��\n" NOR);
        return -1;
}

void append_receiver(object ob)
{
        if (! receiver)
                receiver = ({ ob });
        else
                if (member_array(ob, receiver) == -1)
                        receiver += ({ ob });
}

int accept_object(object me, object ob)
{
        string wid;

        if (clonep(this_object()))
        {
                command("hehe");
                command("say �����汱����ٰ�������");
                return 1;
        }

        if (ob->id("visible bomb"))
        {
                command("say ��Ҫ�ˣ��Ǿͻ������ɡ�");
                return 1;
        }

        if (! stringp(ob->query("money_id")))
        {
                switch (me->query_temp("beichou_refused"))
                {
                case 0:
                        command("heihei");
                        command("say �������������Űɡ�");
                        me->set_temp("beichou_refused", 1);
                        return 0;

                case 1:
                        message_vision(HIC "$N" HIC "����һ�ţ���$n"
                                       HIC "���˳�ȥ���������ʲô��"
                                       "��\n" NOR,
                                       this_object(), me);
                        break;

                case 2:
                        message_vision(HIC "$N" HIC "����һ�ţ��ݺ�"
                                       "�İ�$n" HIC "���˳�ȥ�������"
                                       "��Ȼ���������ң�\n" NOR,
                                       this_object(), me);
                        me->receive_damage("qi", 100);
                        me->receive_wound("qi", 10);
                        break;

                default:
                        message_vision(HIC "$N" HIC "��ŭ��һ�����"
                                       "���ڣ��ͼ�$n" HIC "��ֽƬһ"
                                       "�����˳�ȥ��\n" NOR,
                                       this_object(), me);
                        command("chat* heng " + me->query("id"));
                        me->unconcious();
                        break;
                }

                me->add_temp("beichou_refused", 1);
                me->move("/d/city/beidajie1");
                message_vision(HIC "ֻ����žડ���һ����$N" HIC
                               "�ݺݵ�ˤ���˵��ϡ�\n" NOR, me);
                return -1;
        }

        me->delete_temp("beichou_refused", 1);
        if (stringp(wid = me->query_temp("pending/ask_beichou", 1)))
        {
                object fob;
                int va;

                va = me->query_temp("pending/ask_value");

                if (ob->value() < va)
                {
                        message_vision(CYN "$N" CYN "��Цһ�����������Ǯ��"
                                       "��³�нŻ���ࡣ\n" NOR,
                                       this_object());
                        return 0;
                }

                me->delete_temp("pending/ask_beichou");

                fob = find_player(wid);
                if (! fob || ! me->visible(fob)) fob = find_living(wid);
                if (! fob || ! me->visible(fob) || ! environment(fob))
                {
                        message_vision(CYN "$N" CYN "����ͷ��$n" CYN "�������¡���"
                                       "���һ���������Ϣ�أ���ô��ôһ�����\n" NOR,
                                       this_object(), me);
                        return 0;
                }

                destruct(ob);
                command("whisper " + me->query("id") +
                        " �ݿɿ���Ϣ������˸ղ���" +
                        environment(fob)->short() + "��");

                if (va <= 1000)
                        fob->add("ask_cheap", -1);

                else fob->set("ask_cheap", 3);

                return 1;
        }

        if (ob->value() < 3000)
        {
                message_vision(CYN "$N" CYN "�ӹ�$n" CYN "�ݹ�ȥ��" + ob->name() +
                               NOR + CYN "��������ü�����������Ǯ�����ˣ��㲻Ҫ��"
                               "���Ұɣ�\n" NOR, this_object(), me);
                destruct(ob);
                return 1;
        }

        if ((int)me->query_temp("receive_rumor_time") < time())
                me->set_temp("receive_rumor_time", time());

        me->add_temp("receive_rumor_time", ob->value() / 3000 * 60);
        message_vision(CYN "$N" CYN "�ֵúϲ�£�죬��æ�ӹ�" + ob->name() +
                       CYN "����ͷ�����Ķ�$n" CYN "�����ã��ã�\n" NOR,
                       this_object(), me);

        command("tell " + me->query("id") +
                sprintf(" Ҫ�� %d ������������ҥ����һ���Ҵ������ϵס�",
                        (me->query_temp("receive_rumor_time") - time()) / 60));
        destruct(ob);
        append_receiver(me);
        return 1;
}

int ask_fee()
{
        int n;
        object me;

        me = this_player();
        if (me->query_temp("receive_rumor_time") < time())
        {
                command("say ���󲻹���ʮ�����Ӱ���һ���ӡ�");
                return 1;
        }

        n = me->query_temp("receive_rumor_time") - time();
        n /= 60;
        if (! n)
        {
                command("tell " + me->query("id") +
                        " ���ϵ�ʱ��������������Ϣ�������Ǯ������");
        } else
        {
                command("tell " + me->query("id") +
                        sprintf(" �㻹���� %d ���ӵ���Ϣ��", n));
        }

        message("visoin", CYN + name() + CYN "���ֹ����Ķ�" + me->name() +
                          CYN "˵��һЩ����\n" NOR, environment(me), ({ me }));
        return 1;
}

int ask_bomb()
{
        object ob;
        object me;
        int n;

        me = this_player();
        n = ((int)me->query_temp("receive_rumor_time")) - time();
        if (n < 0) n = 0;        
        n /= 60;
        if (! n)
        {
                command("shake");
                command("say �������������Ҳ���ʶ�㡣");
                return 1;
        }

        if (! (ob = present("visible bomb", this_object())) &&
           query_temp("bomb_count") <= 0)
        {
                command("say ��ϧ���ҵ�������㣬������ͷû������");
                return 1;
        }

        if (! ob) catch(ob = new("/clone/gift/xianxing"));

        if (! ob)
        {
                command("say �ҵ�ը���ܳ��������������ˣ�");
                return 1;
        }

        command("heihei");
        command("say �������չ�������������ϣ��Ҿ͸���һ��ը����");

        if (! environment(ob))
                ob->move(this_object());

        command("give bomb to " + me->query("id"));
        add_temp("bomb_count", -1);
        remove_call_out("restore_bomb");
        call_out("restore_bomb", 150);
        return 1;
}

private void restore_bomb()
{
        set_temp("bomb_count", 1);
}

void receive_report(object user, string verb)
{
        string msg;

        msg = sprintf("��˵%s(%s)��Ҫ��ҥ���ˡ�",
                      user->query("name"), user->query("id"));
        if (random(100) < 7)
        {
                command("heihei");
                command("say " + msg);
        }

        if (! receiver)
                return;

        receiver = filter_array(receiver, (: filter_listener :));
        if (! sizeof(receiver))
        {
                receiver = 0;
                return 0;
        }

        message("vision", HIC "�������ĵĸ����㣺" + msg + "\n",
                receiver, user);
}

private int filter_listener(object ob)
{
        if (! objectp(ob))
                return 0;

        if (present("rumor generator", ob))
                return 1;

        if (ob->query_temp("receive_rumor_time") > time())
                return 1;

        ob->delete_temp("receive_rumor_time");
        return 0;
}

int ask_duwan()
{
        object me;
        object ob;

        me = this_player();
        if (! wizardp(me) || wiz_level(me) < 2)
        {
                command("say �㡭��Ҫ��ҩ��ʲô���¶����Ƿ����ģ�");
                return 1;
        }

        command("consider");
        command("shzi");
        catch(ob = new("/clone/misc/duwan"));
        if (! ob)
        {
                command("say ������˵����⣬����ʱ�ò������ˡ�");
                return 1;
        }
        ob->move(this_object());
        command("give " + ob->query("id") + " to " + me->query("id"));
        command("say ����Ƕ��Ϲ����ģ�ǧ����Ҹ�©�˳�ȥ��");
        return 1;
}

int ask_shedu()
{
        object me;
        object ob;

        me = this_player();
        if (! wizardp(me) || wiz_level(me) < 2)
        {
                command("say �㡭����Ҫ��ҩ��ʲô���¶����Ƿ����ģ�");
                return 1;
        }

        command("heihei");
        command("shzi");
        catch(ob = new("/clone/misc/shedu"));
        if (! ob)
        {
                command("say �߶����˵����⣬����ʱ�ò�������");
                return 1;
        }
        ob->move(this_object());
        command("give " + ob->query("id") + " to " + me->query("id"));
        command("say �����ŷ������Ū�ģ��ɱ�˵���Ҹ���İ���");
        return 1;
}

int ask_list()
{
        object me;

        me = this_player();
        if (me->query_temp("can_buy/beichou/nuclues-bomb", 1))
        {
                command("say ��զ��ô���£��û���˵���顣");
                return 1;
        }
        command("shzi");
        command("whisper " + me->query("id") +
                " �������в��ٺö��������˵úܡ��˵��������ƽ�һ����");
        me->set_temp("can_buy/beichou/nuclues-bomb", 1);
        return 1;
}

int do_list(string arg)
{
        if (arg && ! id(arg))
                return notify_fail("����û������ˡ�\n");

        if (this_player()->query_temp("can_buy/beichou"))
        {
                command("shzi");
                return ::do_list();
        }

        message_vision(CYN "$N" CYN "����æ�ڣ���$n" CYN 
                       "������ֻ����Ϣ���������ٺ١�\n" NOR,
                       this_object(), this_player());
        return 1;
}

int do_buy(string arg)
{
        object me;
        string my_id;

        if (arg && sscanf(arg, "%s from %s", arg, my_id) == 2 && ! id(my_id))
                return notify_fail("����û������ˡ�\n");

        me = this_player();
        if (! me->query_temp("can_buy/beichou"))
        {
                message_vision(CYN "$N" CYN "����˫���Ұڣ���$n" CYN
                               "������˵���˲���" CYN "�����ģ��ҿ�"
                               "����ʵ�ˡ�\n", this_object(), this_player());
                return 1;
        }

        return ::do_buy(arg);
}

mixed ask_cancel()
{
        object me = this_player();
        int t = uptime();

        if (me->is_busy() || me->is_fighting())
                return "����æ������˵�ɣ�\n";

        if (! me->query("quest"))
                return "�߿������ң�\n";

        if (t > 900)
                return "�߿��������ʲôȥ�ˣ�\n";
        
        me->delete("quest");

        return "���ˣ�\n";        
}
