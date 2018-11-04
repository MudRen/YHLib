// storyd.c

#include <ansi.h>

inherit F_DBASE;

// ÿ 20 ��ˢ�¹���
#define REFRESH_TIME    20 * 86400

static string *story_name;

static object  running_story;
static mapping history;
static int step;
int    filter_listener(object ob);

private void init_story();
private void ready_to_start();
private void go_on_process(object ob);

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "���¾���");
        CHANNEL_D->do_channel( this_object(), "sys", "����ϵͳ�Ѿ�������");

        init_story();

        history = allocate_mapping(sizeof(story_name));
        ready_to_start();
}

private void init_story()
{
        CHANNEL_D->do_channel( this_object(), "sys", "����ϵͳ�������й��¡�");
        story_name = get_dir(STORY_DIR + "*.c");
        story_name = map_array(story_name, (: $1[0..<3] :));
        set_temp("last_update", time());
}

private void ready_to_start()
{
        if (time() - query_temp("last_update") > REFRESH_TIME)
                init_story();

        remove_call_out("start_story");
        remove_call_out("process_story");
        call_out("start_story", 1800 + random(300));
}

private void go_on_process(object ob)
{
        remove_call_out("start_story");
        remove_call_out("process_story");
        call_out("process_story", 1, ob);
}

int clean_up()
{
        return 1;
}

object query_running_story()
{
        return running_story;
}

varargs void start_story(string sname)
{
        string *all_story;
        string name;
        object ob;

        ready_to_start();

        if (VERSION_D->is_boot_synchronizing())
                // ����������ͬ���汾����ô�������κι���
                return;

        CHANNEL_D->do_channel(this_object(), "sys", "����ϵͳ��ʼѡ����¡�");

        if (sname)
                all_story = explode(sname, ",");
        else
                all_story = filter_array(story_name, (: $1 == "challenge" ||
                                                        time() - (int)history[$1] > 18000 :));
        while (sizeof(all_story))
        {
                name = all_story[random(sizeof(all_story))];
                if (undefinedp(history[name]))
                        history += ([ name : 0 ]);
                else
                        history[name] = (int)time();

                CHANNEL_D->do_channel(this_object(), "sys",
                                      "����ϵͳѡ���˹���(" + name + ")��");
 
                all_story -= ({ name });
                name = STORY_DIR + name;
                if (ob = find_object(name))
                        destruct(ob);
        
                catch(ob = load_object(name));
                running_story = ob;
        
                if (objectp(ob))
                {
                        step = 0;
                        go_on_process(ob);
                        break;
                }
        }
}

void remove_story(string story)
{
        story_name -= ({ story });
}

string *query_all_story()
{
        return story_name;
}

void process_story(object ob)
{
        mixed line;
        object *listeners;
        string prompt;

        go_on_process(ob);

        if (! objectp(ob))
        {
                ready_to_start();
                return;
        }

        line = ob->query_story_message(step);
        step++;

        prompt = ob->prompt();
        if (! prompt) prompt = HIG "�����´��š�" NOR;
        if (functionp(line)) catch(line = evaluate(line));
        if (stringp(line))
        {
                listeners = filter_array(users(), (: filter_listener :));
                message( "story",  prompt + WHT + line + "\n" NOR, listeners );
        }

        if (intp(line) && ! line)
        {
                ready_to_start();
                destruct(ob);
        }
}

int filter_listener(object ob)
{
        if (ob->query("env/no_story")) return 0;
        return 1;
}

void give_gift(string gift, int amount, string msg)
{
        object ob, pob;
        object env;
        mapping ips;
        string ip, *ks;

        ips = ([ ]);
        foreach (pob in all_interactive())
        {
                if (wizardp(pob) || ! pob->query("born") ||
                    ! living(pob) || ! environment(pob) ||
                    pob->is_ghost() ||
                    environment(pob)->is_chat_room())
                        continue;

                ip = query_ip_number(pob);
                if (undefinedp(ips[ip])) ips[ip] = ({ pob }); else ips[ip] += ({ pob });
        }

        if (sizeof(ips) >= 1)
        {
                // ��Ҫ�������ϵ�IP��¼�Ÿ��뽱Ʒ

                // �漴��һ��IP
                ks = keys(ips);
                ip = ks[random(sizeof(ks))];

                // �ڸ�IP��ַ���漴��ȡһ�����
                pob = ips[ip][random(sizeof(ips[ip]))];

                env = environment(pob);
                while (env && env->is_character())
                        env = environment(env);

                if (! objectp(env)) return;

                tell_room(env, msg);
                while (amount-- > 0)
                {
                        ob = new(gift);
                        ob->move(env);
                }
                CHANNEL_D->do_channel( this_object(),
                        "sys", sprintf(NOR WHT "��Ʒ%s" NOR WHT "������"
                                HIC "%s" NOR WHT "(%O" NOR WHT ")��" NOR,
                                ob->name(), env->short(), env));
        }
}
