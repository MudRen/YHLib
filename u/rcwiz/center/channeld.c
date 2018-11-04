
#pragma optimize
#pragma save_binary

#include <ansi.h>
#include <mudlib.h>
#include <net/macros.h>
#include <net/dns.h>
#include <localtime.h>

inherit F_DBASE;

#define ALLOW_LIST ({ })
#define SPECIAL_NPC     ({ "/adm/npc/youxun" })

#define REMOTE_Q        "/adm/daemons/network/services/remote_q.c"

string remove_addresses(string, int);
int filter_listener(object ppl, string only, object me);

static string msg_log;
static int log_from;

string query_msg_log() { return msg_log; }

mapping channels = ([
        "sys":  ([      "msg_speak": HIR "��ϵͳ���桿%s��%s\n" NOR,
                        "msg_emote": HIR "��ϵͳ���桿%s" NOR,
                        "msg_color": HIR,
                        "only"     : "wiz",
                        "name"     : "ϵͳ",
                        "omit_log" : 1,
                ]),

        "wiz":  ([      "msg_speak": HIY "����ʦƵ����%s��%s\n" NOR,
                        "msg_emote": HIY "����ʦƵ����%s" NOR,
                        "msg_color": HIY,
                        "name"     : "��ʦ",
                        "only"     : "wiz",
                        "intermud" : GCHANNEL,
                        "intermud_emote"   : 1,
                        "intermud_channel" : "wiz",
                        "omit_address": 0,
                        "omit_log" : 1,
                        "filter"   : (: $1["MUDLIB"] == MUDLIB_NAME :)
                ]),

        // 97-10-18 this channel add for display debug message by ken@XAJH
        "debug":([      "msg_speak": HIW "��������Ϣ��%s��%s\n" NOR,
                        "msg_emote": HIW "��������Ϣ��%s" NOR,
                        "msg_color": HIW,
                        "name"     : "����",
                        "only"     : "wiz",
                        "omit_log" : 1,
                ]),

        "inter":([      "msg_speak": HIR "��ͬ�˽�̸��%s��%s\n" NOR,
                        "msg_emote": HIR "��ͬ�˽�̸��%s" NOR,
                        "msg_color": HIR,
                        "only"     : "league",
                        "name_raw" : 1,
                        "name"     : "ͬ��",
                        "omit_log" : 1,
                ]),

        "chat": ([      "msg_speak": HIC "������������%s��%s\n" NOR,
                        "msg_emote": HIC "������������%s" NOR,
                        "msg_color": HIC,
                        "name"     : "����",
                ]),

        "ic"  : ([      "msg_speak": HIC "�������š�%s��%s\n" NOR,
                        "msg_emote": HIC "�������š�%s" NOR,
                        "msg_color": HIC,
                        "intermud" : GCHANNEL,
                        "intermud_emote"   : 1,
                        "intermud_channel" : "ic",
                        "name"     : "����",
                        "filter"   : (: $1["MUDLIB"] == MUDLIB_NAME :)
                ]),

        "bill": ([      "msg_speak": HIY "��ת�ֽ��ס�%s��%s\n" NOR,
                        "msg_color": HIY,
                        "name"     : "����",
                        "name_raw" : 1,
                        "omit_log" : 1,
                ]),

        "ultra": ([     "msg_speak": HIW "���� �� ʦ��%s��%s\n" NOR,
                        "msg_emote": HIW "���� �� ʦ��%s" NOR,
                        "msg_color": HIW,
                        "name"     : "����ʦ",
                        "intermud" : GCHANNEL,
                        "intermud_emote"    : 1,
                        "intermud_channel"  : "rultra",
                        "filter"   : (: $1["MUDLIB"] == MUDLIB_NAME :)
                ]),

        "shout":([      "msg_speak": HIW "%s������Х��%s\n" NOR,
                ]),

        "rumor":([      "msg_speak": HIM "��ҥ������%s��%s\n" NOR,
                        "msg_emote": HIM "��ҥ������%s" NOR,
                        "msg_color": HIM,
                        "name"     : "ҥ��",
                        "anonymous": "ĳ��",
                ]),
        "sing": ([      "msg_speak": HIG "���ĸ����ϡ�%s������%s......\n" NOR,
                        "msg_emote": HIG "���ĸ����ϡ�%s" NOR,
                        "msg_color": HIG,
                        "name"     : "�質",
                ]),
        "party":([      "msg_speak": HIG "�����ﻰ�%s��%s\n" NOR,
                        "msg_emote": HIG "�����ﻰ�%s" NOR,
                        "msg_color": HIG,
                        "only"     : "party",
                        "name"     : "����",
                        "omit_log" : 1,
                ]),
        "family":([     "msg_speak": HIG "��ͬ�Ż��%s��%s\n" NOR,
                        "msg_emote": HIG "��ͬ�Ż��%s" NOR,
                        "msg_color": HIG,
                        "only"     : "family",
                        "name"     : "ͬ��",
                        "omit_log" : 1,
                ]),
        "rultra":([     "msg_speak": WHT "��������ʦ��%s��%s\n" NOR,
                        "msg_emote": WHT "��������ʦ��%s" NOR,
                        "msg_color": WHT,
                        "name"     : "������ʦ",
                        "for_listen": 1,
                ]),
        "member":  ([   "msg_speak": NOR + MAG "����ԱƵ����%s��%s\n" NOR,
                        "msg_emote": NOR + MAG "����ԱƵ����%s" NOR,
                        "msg_color": NOR + MAG,
                        "name"     : "�׻ƻ�Ա",
                        "only"     : "is_member",
                        "omit_log" : 1,
                ]),
       
]);

void create()
{
        // This is required to pass intermud access check.
        seteuid(getuid());
        set("channel_id", "Ƶ������");
}

// ��¼Ƶ����Ϣ����־
void channel_log(string msg, string verb, object user)
{
        string lfn;
        mixed lt;
        int t;

        if (! mapp(channels[verb]) || ! objectp(user) || ! userp(user))
                return;

        if (channels[verb]["omit_log"])
                return;

        if (! stringp(msg_log)) msg_log = "";

        t = time();
        msg_log += sprintf(" %s(%s) on %s\n%s",
                           user->name(1), user->query("id"), log_time(), msg);
        if (strlen(msg_log) > 8000 || t - log_from > 900)
        {
                lt = localtime(t);

                lfn = sprintf("channel/%d-%d-%d", lt[LT_YEAR],
                              lt[LT_MON] + 1, lt[LT_MDAY]);
                assure_file(LOG_DIR + lfn);
                log_file(lfn, msg_log);
                msg_log = "";
                log_from = t;
        }
}

// ����REMOTE_Q����������Ϣ����ʾ֮
void do_remote_channel(object me, string verb, string arg)
{
        object *obs;
        string msg;

        if (undefinedp(channels[verb]) || ! userp(me))
                return;

        // Ok, I will direct send the message to those people listening us.
        obs = all_interactive();
        if (stringp(channels[verb]["only"]))
                obs = filter_array(obs, (: filter_listener :),
                                   channels[verb]["only"], me);

        msg = sprintf(channels[verb]["msg_emote"], arg);
        message("channel:" + verb, msg, obs);
        channel_log(msg, verb, me);

        // �����վ�㷢��EMOTE��Ϣ
        channels[verb]["intermud"]->send_msg(channels[verb]["intermud_channel"],
                                             me->query("id"), me->name(1),
                                             arg, 1,
                                             channels[verb]["filter"]);
}

varargs int do_channel(object me, string verb, string arg, int emote)
{
        object *obs;
        string *tuned_ch, who;
        int is_player;
        string imsg = 0, local;
        string msg;

        string party;
        string family;
        string fname;

        // Check if this is a channel emote.
        if (sizeof(verb) > 2)
        {
                if (verb[sizeof(verb) - 1] == '*')
                {
                        emote = 1;
                        verb = verb[0..<2];
                }
        }

        // Check if this is a channel messsage.
        if (! mapp(channels) || undefinedp(channels[verb])) return 0;

        if (me->is_chatter())
                return notify_fail("�������Ŀǰ����ʹ�ø���Ƶ����\n");

        is_player = playerp(me);
        if (is_player && ! wizardp(me))
        {
                if (! me->query("registered"))
                        return notify_fail("�������ע���Ժ���ܹ�ʹ�ø���Ƶ����\n");

                if (me->query("mud_age") < 1800)
                        return notify_fail("����������ע����ʮ�����Ժ����ʹ��Ƶ�������"
                                           "ʱ���������Ķ�����(help newbie)��\n");

                if (verb == "ic" && me->query("age") < 18)
                        return notify_fail("���������Ժ����ʹ��" + channels[verb]["name"] +
                                           "Ƶ����\n");
        }

        // now we can be sure it's indeed a channel message:
        if (! stringp(arg) || arg == "" || arg == " " ) arg = "...";

        if (ultrap(me))
        {
                if (verb == "chat" && ! me->query("env/no_autoultra"))
                        verb = "ultra";
        } else
                if (is_player && verb == "ultra")
                        return notify_fail("������˴���ʦ��"
                                           "ʹ�����Ƶ���ɣ�\n");

        // player broadcasting need consume jing
        if (userp(me) && ! wizardp(me) && verb == "rumor" &&
            ! objectp(present("rumor generator", me)))
                if (me->query("jing") > 50) me->add("jing", -random(36))
                        ; else
                return notify_fail("���Ѿ�û����ɢ��ҥ���ˣ�\n");

        if (userp(me) && me->ban_say(1)) return 0;

        // check if rumor or chat is blocked
        if (me->query("chblk_on"))
                return notify_fail("���Ƶ�����ر��ˣ�\n");

        if (me->query("doing") == "scheme")
        {
                if (me->query("jing") < 100)
                        return notify_fail("�����ڵľ��񲻼ã���һ����ɡ�\n");
                me->add("jing", -50);
        }

        if (userp(me))
        {
                if (time() - me->query_temp("last_use_channel") < 4)
                {
                        if (me->query_temp("last_message") == arg)
                                return notify_fail("��Ҫ�ڶ�����ʹ��Ƶ��"
                                                   "�����ظ�����Ϣ��\n");
                        me->set_temp("last_message", arg);
                } else
                {
                        me->set_temp("last_message", arg);
                        me->set_temp("last_use_channel", time());
                }

                switch (channels[verb]["only"])
                {
                case "wiz":
                        if (wiz_level(me) < 3)
                                return 0;
                        break;

                case "arch":
                        if (wiz_level(me) < 4)
                                return 0;
                        break;

                case "party":
                        if (! (party = me->query("party/party_name")))
                                return notify_fail("�㻹���ȼ���һ��������˵�ɡ�\n");

                        if (strlen(party) == 6)
                        {
                                party = party[0..1] + " " +
                                        party[2..3] + " " +
                                        party[4..5];
                        }
                        channels[verb]["msg_speak"] = HIG "��" + party +
                                                      "��%s��%s\n" NOR;
                        channels[verb]["msg_emote"] = HIG "��" + party +
                                                      "��%s" NOR;
                        break;

                case "family":
                        if (! (family = me->query("family/family_name")))
                                return notify_fail("�㻹���ȼ���һ��������˵�ɡ�\n");

                        if (strlen(family) == 6)
                        {
                                family = family[0..1] + " " +
                                         family[2..3] + " " +
                                         family[4..5];
                        }
                        channels[verb]["msg_speak"] = HIG "��" + family +
                                                      "��%s��%s\n" NOR;
                        channels[verb]["msg_emote"] = HIG "��" + family +
                                                      "��%s" NOR;
                        break;


                case "league":
                        if (! (fname = me->query("league/league_name")))
                                return notify_fail("�㻹���Ⱥͱ��˽���ͬ����˵�ɡ�\n");

                        switch (strlen(fname))
                        {
                        case 4:
                                fname = "�� " + fname[0..1] + "  " + fname[2..3] + " ��";
                                break;
        
                        case 6:
                                fname = "�� " + fname + " ��";
                                break;
        
                        case 8:
                                fname = "��" + fname + "��";
                                break;
        
                        case 10:
                                fname = "��" + fname[0..7] + "��";
                                break;
                        }
                        channels[verb]["msg_speak"] = HIR + fname + "%s��%s\n" NOR;
                        channels[verb]["msg_emote"] = HIR + fname + "%s" NOR;
                        break;
                }
        }

        if (verb == "shout")
        {
                if (! arg) return notify_fail("����Ҫ���ʲô��\n");
            
                if (! wizardp(me) && userp(me))
                {
                        if (me->query("neili") < 500)
                                return notify_fail("�������̫��޷�������ô���������\n");
                    
                        me->add("neili", - (random(200) + 300));
                }

                msg = HIW + me->name(1) + "������Х��" + arg + "\n" + NOR;
                shout(msg);
                write(HIW + "��������Х��" + arg + "\n" + NOR);
                channel_log(msg, verb, me);
                return 1;
        }

        // If we speaks something in this channel, then must tune it in.
        if (userp(me))
        {
                if (! pointerp(tuned_ch = me->query("channels")))
                {
                        me->set("channels", ({ verb }));
                        write("�����" + channels[verb]["name"] + "Ƶ����\n");
                } else
                if (member_array(verb, tuned_ch) == -1)
                {
                        me->set("channels", tuned_ch + ({ verb }));
                        write("�����" + channels[verb]["name"] + "Ƶ����\n");
                }

                if (channels[verb]["for_listen"])
                {
                        write("���Ƶ��ֻ��������ȡ���˵Ľ�̸��\n");
                        return 1;
                }
        }

        // Support of channel emote
        if (emote && me->is_character())
        {
                string vb, emote_arg, mud;

                if (undefinedp(channels[verb]["msg_emote"]))
                        return notify_fail("���Ƶ����֧�ֱ��鶯�ʡ�\n");

                if (sscanf(arg, "%s %s", vb, emote_arg) != 2)
                {
                        vb = arg;
                        emote_arg = "";
                }

                // internet channel emote
                if (channels[verb]["intermud_emote"])
                {
                        if (sscanf(emote_arg, "%s@%s", emote_arg, mud) == 2 &&
                            htonn(mud) != mud_nname())
                        {
                                REMOTE_Q->send_remote_q(mud, verb, me->query("id"), emote_arg, vb);
                                write("��·ѶϢ���ͳ������Ժ�\n");
                                return 1;
                        }

                        local = sprintf("%s(%s@%s)", me->name(1), capitalize(me->query("id")),
                                                     upper_case(INTERMUD_MUD_NAME));
                        imsg = EMOTE_D->do_emote(me, vb, emote_arg, 3, local,
                                                 channels[verb]["msg_color"]);
                        if (stringp(imsg))
                                arg = replace_string(imsg, local, me->name());
                        else
                                arg = 0;
                } else
                if (verb == "rumor")
                        arg = EMOTE_D->do_emote(me, vb, emote_arg, 2,
                                        channels[verb]["anonymous"],
                                        channels[verb]["msg_color"]);
                else
                        arg = EMOTE_D->do_emote(me, vb, emote_arg, 1,
                                        0, channels[verb]["msg_color"]);
        
                if (! arg && emote == 2)
                        arg = (channels[verb]["anonymous"] ? channels[verb]["anonymous"]
                                                           : me->name(channels[verb]["name_raw"])) +
                                                             vb + "\n";
        
                if (! arg)
                        return 0;
        }

        // Make the identity of speaker.
        if (channels[verb]["anonymous"])
        {
                who = channels[verb]["anonymous"];
                if (userp(me))
                {
                        msg = sprintf("%s(%s)������%sƵ��������Ϣ��",
                                      me->query("name"), me->query("id"), verb);
                        do_channel(this_object(), "sys", msg);
                        SPECIAL_NPC->receive_report(me, verb);
                }
        } else
        if (is_player || ! stringp(who = me->query("channel_id")))
        {
                who = me->name(channels[verb]["name_raw"]);
                if (who == me->name(1))
                        who += channels[verb]["msg_color"] +
                               "[" + capitalize(me->query("id")) + "]";
                if (who[0] == 27) who = NOR + who;
                who += channels[verb]["msg_color"];
        }

        // Ok, now send the message to those people listening us.
        obs = all_interactive();
        if (stringp(channels[verb]["only"]))
                obs = filter_array(obs, (: filter_listener :),
                                   channels[verb]["only"], me);

        if (! arg || arg == "" || arg == " ") arg = "...";

        if (emote)
        {
                string localmsg = arg;
                string ecol = channels[verb]["msg_color"];
                if (emote == 2 && ! arg)
                        arg = me->name(channels[verb]["name_raw"]) +
                              ecol + "[" + me->query("id") + "@" +
                              INTERMUD_MUD_NAME + "]" + arg + "\n";
                if (! stringp(arg)) return 0;

                if (channels[verb]["msg_emote"])
                        localmsg = remove_addresses(arg, 0); // 98-1-22 14:30

                if (channels[verb]["omit_address"])
                        localmsg = remove_addresses(arg, 1);
                else
                if (channels[verb]["intermud_emote"])
                        localmsg = remove_addresses(arg, 0);

                if (! stringp(localmsg)) return 0;
                msg = sprintf(channels[verb]["msg_emote"],
                              sprintf(localmsg, ecol, ecol, ecol));
                message("channel:" + ((verb == "ultra") ? "chat" : verb), msg, obs);
                channel_log(msg, verb, me);
        } else
        {
                msg = sprintf(channels[verb]["msg_speak"], who, arg);
                message("channel:" + ((verb == "ultra") ? "chat" : verb), msg, obs);
                channel_log(msg, verb, me);
        }


        if (! undefinedp(channels[verb]["intermud"]) && me->is_character())
        {
                channels[verb]["intermud"]->send_msg(channels[verb]["intermud_channel"],
                                                     me->query("id"), me->name(1),
                                                     imsg ? imsg : arg, emote,
                                                     channels[verb]["filter"]);
        }

        return 1;
}

int filter_listener(object ppl, string only, object me)
{
        // Don't bother those in the login limbo.
        if (! environment(ppl)) return 0;

        switch (only)
        {
        case "arch":
                return (wiz_level(ppl) >= 4);

        case "wiz":
                return (wiz_level(ppl) >= 3);

        case "family":
                return (ppl->query("family/family_name") == me->query("family/family_name"));

        case "party":
                return (ppl->query("party/party_name") == me->query("party/party_name"));

        case "league":
                return (ppl->query("league/league_name") == me->query("league/league_name"));
        }

        return 1;
}

string remove_addresses(string msg, int all)
{
        int i;
        mixed tmp;
        string pattern;

        if (! stringp(msg)) return msg;
        if (all)
                pattern = "[(][A-Za-z]+@[a-zA-Z]+[0-9]+[.]?[)]";
        else
                pattern = "[(][A-Za-z]+@" + INTERMUD_MUD_NAME + "[)]";

        tmp = reg_assoc(msg, ({ pattern }), ({ 1 }));

        if (! arrayp(tmp)) return msg;
        msg = "";
        for (i = 0; i < sizeof(tmp[0]); i++)
                if (tmp[1][i] == 0) msg += tmp[0][i];
        return msg;
}

