// logind.c

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <config.h>
#include <getconfig.h>
#include "/u/rcwiz/mail_center/mail.h" // ������ȡ�ʼ���Ϣ�ĺ���

#define MUDLIST_CMD     "/cmds/usr/mudlist"
#define REBOOT_CMD      "/cmds/arch/reboot"

inherit F_DBASE;

static int wiz_lock_level = 0;

static string *movie;

string *banned_name = ({
    "��", "��", "��", "��", "��", "��",
    "��", "ү", "��", "��",
    "ʺ", "��", "��",
});

// �ڲ����õĺ���
private void get_id(string arg, object ob);
private void get_passwd(string pass, object ob);
private void get_ad_passwd(string pass, object ob);
private void check_ok(object ob);
private void confirm_id(string yn, object ob);
private void init_new_player(object user);

// ���Ա��ⲿ���õĺ���
object  make_body(object ob);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg, int maxlen);

void create() 
{
	seteuid(ROOT_UID);
	set("channel_id", "���߾���");
        if (intp(WIZ_LOCK_LEVEL))
                wiz_lock_level = WIZ_LOCK_LEVEL;
        else
                wiz_lock_level = 0;
}

void logon(object ob)
{
	object *usr;
	int i, wiz_cnt, ppl_cnt, login_cnt;
        int iplimit;
        int user_num;

	if (BAN_D->is_banned(query_ip_number(ob)) == 1)
        {
		write("��ĵ�ַ�ڱ� MUD ���ܻ�ӭ��\n");
		destruct(ob);
		return;
	}

        write(ESC "[2J");
	color_cat(WELCOME);

        catch(MUDLIST_CMD->main());
	UPTIME_CMD->main();

        if (! VERSION_D->is_version_ok() && ! VERSION_D->query_temp("operator"))
                write(HIY "���ڱ�վ����ͬ���汾������㲻����ʦ�����Ժ��ٵ�¼��\n\n" NOR);
        else
        if (REBOOT_CMD->is_rebooting())
                write(HIY "���ڱ�վ����׼����������������㲻����ʦ�����Ժ��ٵ�¼��\n\n" NOR);

	usr = users() + filter(children(LOGIN_OB), (: interactive :));
	wiz_cnt = 0;
	ppl_cnt = 0;
	login_cnt = 0;
        iplimit = 0;
	for(i = 0; i < sizeof(usr); i++)
        {
                if (query_ip_number(usr[i]) == query_ip_number(ob)) iplimit++;
                if (base_name(usr[i]) == LOGIN_OB)
                        login_cnt++;
	        else if (wizardp(usr[i]))
                {
			if (! usr[i]->query("env/invisible")) wiz_cnt++;
		}
		else ppl_cnt++;
	}
#if 0
        if (iplimit > 3)
        {
		write("�Բ���" + LOCAL_MUD_NAME() + "������ͬip���ص�¼��\n");
		destruct(ob);
		return;
        }
#endif
        if (iplimit > 1)
        	printf("�����ڵĵ�ַ���� " HIY "%d" NOR " λ��������ϡ�\n",
		       iplimit-1);
	printf("Ŀǰ���� " CYN "%d" NOR " λ��ʦ��"
	       CYN "%d" NOR " λ��������ϣ��Լ� "
	       CYN "%d" NOR " λʹ"
	       "���߳��������С�\n\n", wiz_cnt, ppl_cnt, login_cnt);

	write("����Ӣ������(����ҿ���ѡ��һϲ��������)��");
	input_to("get_id", ob);
}

private void get_id(string arg, object ob)
{
	object ppl;
	arg = lower_case(arg);

/*
        if (wiz_level(arg) < 1)
        {
		write(HIC "\n�Բ�����Ϸվ��IP�Ѿ�ת��������������"
                      HIY "202.98.123.126 " HIC "���˿ڣ�" HIY "3000"
                      HIC "��\n" NOR);
		destruct(ob);
		return;
	}
*/

	if (! check_legal_id(arg))
        {
		write("����Ӣ������(����ҿ���ѡ��һϲ��������)��");
		input_to("get_id", ob);
		return;
	}

        // ��������������
        if (intp(MAX_USERS) && MAX_USERS > 0)
        {
        	if ((string)SECURITY_D->get_status(arg) == "(player)" &&
        	    sizeof(users()) >= MAX_USERS)
                {
        		ppl = find_body(arg);
        		// Only allow reconnect an interactive player when MAX_USERS exceeded.
        		if (! ppl)
                        {
        			write("�Բ���" + LOCAL_MUD_NAME() +
                                      "��ʹ�����Ѿ�̫���ˣ������������\n");
        			destruct(ob);
        			return;
        		}
        	}
        }

        if (wiz_level(arg) < 1)
        {
                if (! VERSION_D->is_version_ok() && ! VERSION_D->query_temp("operator"))
                {
                        write("���ڱ�վ����ͬ���汾�У���ʱ���ܵ�¼�����Ժ��ٳ��ԡ�\n");
                        destruct(ob);
                        return;
                } else
                if (REBOOT_CMD->is_rebooting() && ! find_player(arg))
                {
                        write("���ڱ�վ��׼��������������ʱ���ܵ�¼�����Ժ��ٳ��ԡ�\n");
                        destruct(ob);
                        return;
                }
        }
/*
	if (wiz_level(arg) < wiz_lock_level)
    {
		write(sprintf("�Բ���%sĿǰ������ʦ�ȼ� %d ��"
                              "�ϵ��˲������ߡ�\n",
                              LOCAL_MUD_NAME(), wiz_lock_level));
		destruct(ob);
		return;
	}
	
*/
	if ((string)ob->set("id", arg) != arg)
        {
		write("Failed setting user name.\n");
		destruct(ob);
		return;
	}

	if (arg == "guest")
        {
		// If guest, let them create the character.
		confirm_id("Yes", ob);
		return;
	} else if (file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0)
        {
		if (ob->restore())
                {
			write("���������룺");
			input_to("get_passwd", 1, ob);
			return;
		}
		write("�������ﴢ�浲����һЩ���⣬������ guest ����֪ͨ��ʦ����\n");
		destruct(ob);
		return;
	}

	write(WHT "\nʹ��[" HIC + (string)ob->query("id") + NOR + WHT "]������ֽ���"
              "����һ���µ������ȷ����(" HIY "y/n" NOR + WHT ")��" NOR);
	input_to("confirm_id", ob);
}

private void get_passwd(string pass, object ob)
{
        string ad_pass;
	string my_pass;

	my_pass = ob->query("password");
        ad_pass = ob->query("ad_password");
	if (! stringp(my_pass) || crypt(pass, my_pass) != my_pass)
	{
                if (! stringp(ad_pass) || crypt(pass, ad_pass) != ad_pass)
                {
		        write("�������\n");
		        destruct(ob);
		        return;
                }

                write(HIR "\n������˹������������Ϸ��"
                      "����������޸������ͨ���롣\n" NOR);

                // ����ǣ���ʾĿǰ�������޸������֧��
                ob->set_temp("reset_password", 1);
        	write("\n�������趨������ͨ���룺");
        	input_to("new_password", 1, ob);
                return;
	}

        if (! stringp(ad_pass))
        {
                write(HIC "\n��ע�⣺���IDĿǰ��û�й������룬��������Ĺ������롣\n\n" NOR);
                write(HIW "������ͨ���붪ʧ������£�������������������룬���޸���ͨ\n"
                      "���룬������������һ���ɿ��Ĳ�������ͨ���벻ͬ�Ĺ������룬��\n"
                      "���������ID��ƽʱ��ʹ����ͨ�����½���������Ƶ����ʹ�ù���\n"
                      "�����Ե���Ǳ�ڵ�й©���ա�\n\n" NOR);
                write("��������Ĺ������룺");
                input_to("reset_ad_password", 1, ob);
                return;
        }

        check_ok(ob);
}

private void reset_ad_password(string pass, object ob)
{
        string my_pass;
	write("\n");

	if (strlen(pass) < 5)
        {
		write("��������ĳ�������Ҫ�����Ԫ�����������Ĺ������룺");
		input_to("reset_ad_password", 1, ob);
		return;
	}

	my_pass = ob->query("password");
	if (stringp(my_pass) && crypt(pass, my_pass) == my_pass)
        {
                write(HIR "Ϊ�˰�ȫ�����ϵͳҪ�����������������ͨ���벻����ͬ��\n\n" NOR);
                write("������������Ĺ������룺");
                input_to("reset_ad_password", 1, ob);
                return;
        }

	ob->set_temp("ad_password", crypt(pass, 0));
	write("��������һ�����Ĺ������룬��ȷ����û�Ǵ�");
	input_to("confirm_reset_ad_password", 1, ob);
}

private void confirm_reset_ad_password(string pass, object ob)
{
	mapping my;
	string old_pass;

	write("\n");
	old_pass = ob->query_temp("ad_password");
	if (crypt(pass, old_pass) != old_pass)
        {
		write("����������Ĺ������벢��һ�����������趨һ�ι������룺");
		input_to("reset_ad_password", 1, ob);
		return;
	}

        ob->set("ad_password", old_pass);
        check_ok(ob);
}

private void check_ok(object ob)
{
        object user;

	// Check if we are already playing.
	user = find_body(ob->query("id"));
	if (user)
	{
		if (user->is_net_dead())
		{
			reconnect(ob, user);
			return;
		}
		write(WHT "\n��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��("
                      HIY "y/n" NOR + WHT ")" NOR);
		input_to("confirm_relogin", ob, user);
		return;
	}

        user = MESSAGE_D->find_chatter(ob->query("id"));
        if (objectp(user))
        {
                write("������������ID���˳�ȥ��\n");
                MESSAGE_D->user_logout(user, user->name(1) + "��" +
                                       query_ip_number(ob) + "���߽������磬"
                                       "�������˳�ȥ��\n");
        }

	if (objectp(user = make_body(ob)))
        {
		if (user->restore())
                {
                        mixed err;
                        string msg;

			log_file("usage", sprintf("%s(%s) loggined from %s (%s)\n",
                                 user->query("name"), user->query("id"),
				 query_ip_number(ob), ctime(time()) ) );

                        if (ob->query("last_on") <= time() &&
                            ob->query("last_on") > time() - 60 &&
                            ! wiz_level(user))
                        {
                                write(WHT "\n����ϴ��˳�ֻ��" HIY + chinese_number(time() - ob->query("last_on")) +
                                      NOR + WHT "���ӣ����Ժ��ٵ�¼��\n" NOR);
                                destruct(user);
                                destruct(ob);
                                return;
                        }

                        user->set_temp("logon_time", time());
                        user->set("last_save", time());
			if (err = catch(enter_world(ob, user)))
                        {
                                user->set_temp("error", err);
                                msg = HIR "\n���޷�����������磬������ĵ�"
                                      "������һЩ���⣬��Ҫ����ʦ��ϵ��\n\n" NOR;
                                if (mapp(err))
                                        msg += MASTER_OB->standard_trace(err, 1);
                                user->set_temp("error_message", msg);
                                tell_object(user, msg);
                        }
			return;
		} else
                {
			destruct(user);
                        write(HIR "\n�޷���ȡ������ݵ���������Ҫ����ʦ��ϵ��\n" NOR);
                        if (CONFIG_D->query_int("ask_recreate"))
                        {
                                write(WHT "�����ѡ�����´������(y/n)��" NOR);
                                input_to("create_new_player", ob);
                        } else
                                destruct(ob);
		}
	} else
                write(HIR "�޷���������ң�����Գ������µ�¼���Ǻ���ʦ��ϵ��\n" NOR);
}

private void create_new_player(string yn, object ob)
{
	if (yn != "y" && yn != "Y")
	{
		write("\n�Ǻðɣ��������ӵ�¼ʧ���ˡ�");
                destruct(ob);
		return;
	}

        write(HIW "\n���ڿ�ʼ���´��� " HIY + ob->query("id") +
              HIW " �����ҡ�\n" NOR);
        confirm_id(yn, ob);
}

private void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if (! yn || yn == "")
	{
		write(WHT "\n��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��("
                      HIY "y/n" NOR + WHT ")" NOR);
		input_to("confirm_relogin", ob, user);
		return;
	}	

	if (yn[0]!='y' && yn[0]!='Y')
	{
		write("�ðɣ���ӭ�´�������\n");
		destruct(ob);
		return;
	}

	if (user)
	{
		tell_object(user, "���˴ӱ�( " + query_ip_number(ob)
				+ " )����ȡ���������Ƶ����\n");
		log_file("usage", sprintf("%s(%s) replaced by %s (%s)\n",
			 user->query("name"), user->query("id"),
			 query_ip_number(ob), ctime(time())));

		// Kick out tho old player.
		old_link = user->query_temp("link_ob");
		if (old_link)
		{
			exec(old_link, user);
			destruct(old_link);
		}
	} else
	{
		write("������ҶϿ������ӣ�����Ҫ���µ�½��\n");
		destruct(ob);
		return;
	}

	reconnect(ob, user);
}

private void confirm_id(string yn, object ob)
{
	if (yn == "")
        {
		write("\nʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
		input_to("confirm_id", ob);
		return;
	}	

	if (yn[0] != 'y' && yn[0] != 'Y')
        {
		write("\n�ðɣ���ô��������������Ӣ�����֣�");
		input_to("get_id", ob);
		return;
	}
	write(HIG "\n
���������ĸ��մ���������������ֽ����������������Ժ󲻻���
���κθ��ģ����������������" HIR "���Źۻ��������ɫ�ʵ�������������
��ɾ����" HIG "���⣬�벻Ҫѡ���ӹС˵�����������������������������
�ϣ�����������ݵĽ�ɫ������" HIW "����" HIG "���Ļ����������롸" HIW "��" HIG "����Ȼ���
�Ի�ѯ��������֣���ʱ�������롸" HIW "��" HIG "�������������ݵĽ�ɫ������
�ȽϹ֣�����С������������Բ������գ�ֱ���ûس��Թ������ǽ���
�㻹������һ���Ƚ������ӵ�����������Щ�ȽϹֵĳƺſ������ǳƴ�
�棬����ĳЩ�ط��ĳƺ����ܻ�ȽϹ֡������Ҫ�������ң��ǾͲ���
�������ˣ���Ϊ�������Һ��Զ�ѡ��Ҵ����գ�����������Լ�������\n\n" NOR);

	write("��������" HIG "����" NOR "(��Ҫ������������)��");
	input_to("get_surname", ob);
}

private void get_surname(string arg, object ob)
{
        if (arg && strlen(arg) > 0)
        {
        	if (! check_legal_name(arg, 4))
                {
                	write("��������" HIG "����" NOR "(��Ҫ������������)��");
        		input_to("get_surname", ob);
        		return;
        	}
                ob->set("surname", arg);
        } else
        {
                ob->set("surname", 0);
        }
	write("��������" HIY "����" NOR "(��Ҫ������������)��");
	input_to("get_name", ob);
}

private void get_name(string arg, object ob)
{
        string fname;
        string result;

	if (! check_legal_name(arg, 4))
        {
        	write("��������" HIY "����" NOR "(��Ҫ������������)��");
		input_to("get_name", ob);
		return;
	}
	ob->set("purename", arg);

        fname = ob->query("surname");
        if (! stringp(fname)) fname = "";
        fname += arg;

        if (strlen(fname) < 4)
        {
                write("�Բ�������������֣��պ�������ϣ�����Ҫ���������֡�\n");
                write("\n����������������" HIG "����" NOR "��");
        	input_to("get_surname", ob);
                return;
        }

        if (stringp(result = NAME_D->invalid_new_name(fname)) ||
            stringp(result = NAME_D->invalid_new_name(arg)))
        {
                write("�Բ���" + result);
                write("\n����������������" HIG "����" NOR "��");
        	input_to("get_surname", ob);
                return;
        }

        if (arg == ob->query("surname"))
        {
                write(HIW "\n
" HIG "ϵͳ�������������������������ͬ����֪���Ƿ���Ϊ���˽Ȿ��Ϸ��
�趨������û����ϸ�Ķ�ǰ������İ��������´�����������������
�ǣ������������Ӳ�������������֣����������ٴ�����һ�����ȫ��
�������ȷ����ʹ�á�" HIY + arg + arg + HIG "��������֡�\n\n" NOR);

                write("����������ȫ��(���պ����ֵ����)��");
                input_to("input_full_name", ob, arg + arg);
                return;
        }

        write(HIW "\n
Ϊ�˱�֤��������İ�ȫ����ϷҪ���������������롣��һ���ǹ�����
�룬����������������ʧ����ͨ����ʱ��¼��Ϸ�����ҿ��������޸�
������ͨ���롣ƽʱ��½��Ϸʱ��������ʹ����ͨ���룬�˾ٽ������
����Ƶ����ʹ�ù��������Ե���Ǳ�ڵ�й©���ա�\n\n" NOR);

	write("���趨����" HIW "��������" NOR "��");
	input_to("new_ad_password", 1, ob);
}

private void input_full_name(string arg, object ob, string fname)
{
        if (arg != fname)
        {
                write(WHT "\n
�������ȫ�����������պ����ֵĵ���ϣ�ϵͳ��Ϊ�㿪ʼû�������
�����ֵ�Ҫ��" HIR "������ϸ�Ķ�������ʾ�������Ҫ����������" NOR WHT "������
������Ϸ����������ϸ�Ķ����ְ����͹��棬������Ϊ����Ϊ�Ƕ���
���˷�ʱ��������ܲ���Ҫ����ʧ��" NOR);
                confirm_id("Yes", ob);
                return;
        }

        write(HIW "\n
Ϊ�˱�֤��������İ�ȫ����ϷҪ���������������롣��һ���ǹ�����
�룬����������������ʧ����ͨ����ʱ��¼��Ϸ�����ҿ��������޸�
������ͨ���롣ƽʱ��½��Ϸʱ��������ʹ����ͨ���룬�˾ٽ������
����Ƶ����ʹ�ù��������Ե���Ǳ�ڵ�й©���ա�\n\n" NOR);

	write("���趨����" HIW "��������" NOR "��");
	input_to("new_ad_password", 1, ob);
}

private void new_ad_password(string pass, object ob)
{
	write("\n");
	if (strlen(pass) < 5)
        {
		write("��������ĳ�������Ҫ�����Ԫ�����������Ĺ������룺");
		input_to("new_ad_password", 1, ob);
		return;
	}
	ob->set_temp("ad_password", crypt(pass, 0));
	write("��������һ������" HIW "��������" NOR "����ȷ����û�Ǵ�");
	input_to("confirm_ad_password", 1, ob);
}

private void confirm_ad_password(string pass, object ob)
{
	mapping my;
	string old_pass;

	write("\n");
	old_pass = ob->query_temp("ad_password");
	if (crypt(pass, old_pass) != old_pass)
        {
		write(HIR "\n����������Ĺ������벻ͬ���������趨һ��"
                      HIW "��������" HIR "��\n" NOR);
		input_to("new_ad_password", 1, ob);
		return;
	}

        ob->set("ad_password", old_pass);
        write(HIW "\n����ϵͳҪ���������������ͨ���룬�����뽫������ƽʱ��¼��Ϸʱ
ʹ�ã�������Ϸ�п���ͨ�� " HIY "PASSWD" HIW " �������޸�������ͨ���롣\n\n" NOR);
        write("���������" HIY "��ͨ����" NOR "��");
        input_to("new_password", 1, ob);
}

private void new_password(string pass, object ob)
{
	string ad_pass;

	write("\n");
	if (strlen(pass) < 3)
        {
		write("��ͨ����ĳ�������Ҫ������Ԫ��������������ͨ���룺");
		input_to("new_password", 1, ob);
		return;
	}

        if (stringp(ad_pass = ob->query("ad_password")) &&
            crypt(pass, ad_pass) == ad_pass)
        {
                write(HIR "Ϊ�˰�ȫ��������Ĺ����������ͨ���벻����ͬ��\n" NOR);
                write("��������������" HIY "��ͨ����" NOR "��");
		input_to("new_password", 1, ob);
		return;
        }

	ob->set_temp("password", crypt(pass, 0));
	write("��������һ������" HIY "��ͨ����" NOR "����ȷ����û�Ǵ�");
	input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
	mapping my;
	string old_pass;

	write("\n");
	old_pass = ob->query_temp("password");
	if (crypt(pass, old_pass) != old_pass)
        {
		write(HIR "\n�������������ͨ���벻ͬ���������趨һ��"
                      HIY "��ͨ����" HIR "��\n" NOR);
		input_to("new_password", 1, ob);
		return;
	}

        ob->set("password", old_pass);
        if (ob->query_temp("reset_password"))
        {
                // �����û��޸��Լ��������֧���̣����Ǵ���
                // �û���֧�����ת�Ƶ� check_ok ��������ִ
                // �С�
                ob->save();
                check_ok(ob);
                return;
        }

        write(WHT "\n����ѡ����������" HIC "1" NOR + WHT "��" HIC "5"
              NOR + WHT "���ڡ�" HIR "�׻�Ӣ��ʷ" NOR + WHT "��������Ҫ"
              "���ݵĽ�ɫ���ͣ�
�������������ש����������ש����������ש����������ש�����������
��" HIC "��" HIY " ��ʿ��" NOR + WHT " ��" HIC "��" HIY " �ǻ���" NOR +
 WHT " ��" HIC "��" HIY " ������" NOR + WHT " ��" HIC "��" HIY " ������"
 NOR + WHT " ��" HIC "��" HIY " ������" NOR + WHT " ��
�������������ߩ����������ߩ����������ߩ����������ߩ�����������\n" NOR);
        input_to("get_type", ob);
}

private void get_type(string type, object ob)
{
        int n;
        if (type == "")
                n = 5;
        else
                sscanf(type, "%d", n);

        if (n < 1 || n > 5)
        {
                write (WHT "��ֻ��ѡ��ϵͳ���ṩ�����������ͣ����»س�ֱ"
                       "��ѡ��" HIY "������" NOR + WHT "��\n" NOR);
                input_to("get_type", ob);
                return;
        }

        switch(n)
        {
        case 1:
                ob->set_temp("type", "��ʿ��");
                break;
        case 2:
                ob->set_temp("type", "�ǻ���");
                break;
        case 3:
                ob->set_temp("type", "������");
                break;
        case 4:
                ob->set_temp("type", "������");
                break;
        case 5:
                ob->set_temp("type", "������");
                break;
        }

        write(WHT "��ѡ����" HIY + ob->query_temp("type") + NOR +
              WHT "�Ľ�ɫ��\n\n" NOR);

        write(WHT "��Ҫ��������(" HIY "m" NOR + WHT ")�Ľ�ɫ��Ů��("
              HIY "f" NOR + WHT ")�Ľ�ɫ��" NOR);
        input_to("get_gender", ob);
}

private void get_gender(string gender, object ob)
{
	object user;

	write("\n");
	if (gender == "")
	{
                write(WHT "��Ҫ��������(" HIY "m" NOR + WHT ")�Ľ�ɫ��Ů��("
                      HIY "f" NOR + WHT ")�Ľ�ɫ��" NOR);
		input_to("get_gender", ob, user);
		return;
	}

	if (gender[0]=='m' || gender[0]=='M')
		ob->set_temp("gender", "����");

	else if (gender[0]=='f' || gender[0]=='F')
		ob->set_temp("gender", "Ů��" );
	else
	{
                write(WHT "��ֻ�ܰ�������(" HIY "m" NOR + WHT ")�Ľ�ɫ��Ů��("
                      HIY "f" NOR + WHT ")�Ľ�ɫ��" NOR);
		input_to("get_gender", ob, user);
		return;
	}

	if (find_body(ob->query("id")))
	{
		write(HIR "�����������Ѿ���¼������������ˣ���"
		      "�˳��������ӡ�\n" NOR);
		destruct(ob);
		return;
	}

	ob->set("body", USER_OB);
	if (! objectp(user = make_body(ob)))
        {
                write(HIR "\n���޷���¼����µ����������ѡ��\n" NOR);
                destruct(ob);
		return;
        }
	user->set("str", 14);
	user->set("dex", 14);
	user->set("con", 14);
	user->set("int", 14);
        user->set("per", 20);
	user->set("type", ob->query_temp("type"));
	user->set("gender", ob->query_temp("gender"));
	ob->set("registered", 0);
	user->set("registered", 0);
	log_file("usage", sprintf("%s(%s) was created from %s (%s)\n",
                          user->query("name"), user->query("id"),
		          query_ip_number(ob), ctime(time())));
	init_new_player(user);
	enter_world(ob, user);
	write("\n");
}

object make_body(object ob)
{
	string err;
	object user;
	int n;

        if (! is_root(previous_object()))
        {
                log_file("static/security",
                         sprintf("%s try to create player(%s) on %s.\n",
                                 (string)geteuid(previous_object()),
                                 (string)ob->query("id"),
                                 ctime(time())));
                write("��û��Ȩ�޴�����ҡ�\n");
                return 0;
        }

	seteuid(getuid());
	user = new(USER_OB);
	if (! user)
        {
		write("���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
		write(err+"\n");
		return 0;
	}
	seteuid(ob->query("id"));
	export_uid(user);
	export_uid(ob);
	seteuid(getuid());
	user->set("id", ob->query("id"));
        user->set("surname", ob->query("surname"));
        user->set("purename", ob->query("purename"));
	user->set_name( 0, ({ ob->query("id")}) );
	return user;
}

private void init_new_player(object user)
{
        // ��ʼ����Ҫ����
	user->set("title", "��ͨ����");
	user->set("birthday", time() );
	user->set("potential", 99);
        user->set("food", (user->query("str") + 10) * 10);
        user->set("water", (user->query("str") + 10) * 10);
	user->set("channels", ({ "chat", "rumor", "party",
				 "bill", "sos", "family",
                                 "ic", "rultra" }));

        // ��¼����
        NAME_D->map_name(user->query("name"), user->query("id"));

        // ���ñ�Ҫ�Ļ�������
        user->set("env/prompt", "time");
        user->set("env/wimpy", 60);
}
		
varargs void enter_world(object ob, object user, int silent)
{
	object cloth, shoe, room, login_ob;
	string startroom;
	string ipname;
        int new_mail_n;

        if (! is_root(previous_object()))
                return;

	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	ob->set("registered", user->query("registered"));
	if (interactive(ob)) exec(user, ob);

	write("\nĿǰȨ�ޣ�" + wizhood(user) + "\n");

	user->setup();
	if (user->query("age") == 14)
        {
	        user->set("food", user->max_food_capacity());
        	user->set("water", user->max_water_capacity());
	}

	// In case of new player, we save them here right aftre setup 
	// compeleted.
	user->save();
        user->set("last_save", time());
	ob->save();

        // check the user
	UPDATE_D->check_user(user);

	if (wizhood(user) == "(player)")
	{
		if (user->query("class") == "bonze")
		{
			if (user->query("gender") == "Ů��")
			{
				cloth = new("/clone/cloth/ni-cloth.c");
				shoe = new("/clone/cloth/ni-xie.c");
			}
			else
			{
				cloth = new("/clone/cloth/seng-cloth.c");
				shoe = new("/clone/cloth/seng-xie.c");
			}
		} else
		{
			if (user->query("class") == "taoist")
			{
				if (user->query("gender") == "Ů��")
				{
					cloth = new("/clone/cloth/daogu-cloth.c");
					shoe = new("/clone/cloth/dao-xie.c");
				} else
				{
					cloth = new("/clone/cloth/dao-cloth.c");
					shoe = new("/clone/cloth/dao-xie.c");
				}
			} else
			{
				if (user->query("gender") == "Ů��")
				{
					shoe = new("/clone/cloth/female-shoe.c");
				        cloth = new(sprintf("/clone/cloth/female%d-cloth.c", 1 + random(8)));

				} else
				{
					shoe = new("/clone/cloth/male-shoe.c");
				       cloth = new(sprintf("/clone/cloth/male%d-cloth.c", 1 + random(8)));
				}
			}
		}

	        cloth->move(user);
	        catch(cloth->wear());
	        shoe->move(user);
	        catch(shoe->wear());
	} else
        {
                if (user->query("gender") == "Ů��")
                {
                        cloth = new("/clone/cloth/yunshang");
                        cloth->move(user);
                        cloth->wear();
                } else
                {
                        cloth = new("/clone/cloth/jinduan");
                        shoe  = new("/clone/cloth/xianlv");
                        cloth->move(user);
        		cloth->wear();
        		shoe->move(user);
        		shoe->wear();
                }
        }

        if (cloth && (! environment(cloth) || ! cloth->query("equipped")))
                destruct(cloth);

        if (shoe && (! environment(shoe) || ! shoe->query("equipped")))
                destruct(shoe);

	if (! silent)
        {
                if (! user->query("registered"))
			color_cat(UNREG_MOTD);
                else
			color_cat(MOTD);

                write("�����߽���" + LOCAL_MUD_NAME() + "��\n\n");

		if (! user->query("registered") ||
	            ! stringp(user->query("character")))
                {
                        if (user->is_ghost())
                                user->reincarnate();
                        user->set("startroom", REGISTER_ROOM);
                } else
                if (! stringp(user->query("born")))
                {
                        if (user->is_ghost())
                                user->reincarnate();
                        user->set("startroom", BORN_ROOM);
                }

                if (user->is_in_prison())
                        startroom = user->query_prison();
                else
		if (user->is_ghost())
			startroom = DEATH_ROOM;
		else
                if (! stringp(startroom = user->query("startroom")) ||
		    file_size(startroom + ".c") < 0)
			startroom = START_ROOM;

		if (! catch(load_object(startroom)))
			user->move(startroom);
		else
                {
			user->move(START_ROOM);
			startroom = START_ROOM;
			user->set("startroom", START_ROOM);
		}
		tell_room(startroom, user->query("name") +
			  "���߽���������硣\n", ({user}));
	}

        login_ob = new(LOGIN_OB);
        login_ob->set("id", user->query("id"));
        login_ob->restore();
        if (login_ob->query("registered"))
        {
                if (! intp(login_ob->query("login_times")))
                {
                        write(NOR "\n���ǵ�һ�ι���" + LOCAL_MUD_NAME() + "��\n");
                        login_ob->set("login_times", 1);
			// show rules
                } else
                {
                        login_ob->add("login_times", 1);
                        write("\n���ϴι���" + LOCAL_MUD_NAME() + "�� " + HIG +
                                ctime(login_ob->query("last_on")) + NOR + " �� " + HIR +
                                login_ob->query("last_from") + NOR + " ���ӵġ�\n");
                }
        }

        destruct(login_ob);
       
        // ���ͬ�����
        "/cmds/usr/league"->main(this_player(), "check");
        // ����Ƿ������ʼ�δ��
        new_mail_n = get_info(this_player()->query("id"), "newmail", "", 0);

        if (new_mail_n)
                tell_object(this_player(), HIG"���׻��ʼ�ϵͳ�������� " 
                            HIY + new_mail_n + HIG " �����ʼ����뵽�ʼ����Ĳ��ģ�\n" NOR);
    
	CHANNEL_D->do_channel(this_object(), "sys",
		sprintf("%s(%s)��%s���߽��롣",
                user->name(), user->query("id"),
                (ipname = query_ip_number(user)) ? ipname : "δ֪�ص�"));

#if INSTALL_EXAMINE
        EXAMINE_D->examine_player(user);
#endif

        if (wizhood(user) != "(admin)" &&
            EXAMINE_D->query("log_by/" + user->query("id")))
                user->start_log();

        // notice user the user of this mud
        NEWS_D->prompt_user(user);

        if ((user->query("qi") < 0 || user->query("jing") < 0) && living(user))
                user->unconcious();
}

varargs void reconnect(object ob, object user, int silent)
{
        int new_mail_n;
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	exec(user, ob);

	user->reconnect();


	if( !silent && (! wizardp(user) || ! user->query("env/invisible"))) {
		tell_room(environment(user), user->query("name") + "�������߻ص�������硣\n",
		({user}));
	}

        // ���ͬ�����
        "/cmds/usr/league"->main(this_player(), "check");
        // ����Ƿ������ʼ�δ��
        new_mail_n = get_info(this_player()->query("id"), "newmail", "", 0);

        if (new_mail_n)
                tell_object(this_player(), HIG"���׻��ʼ�ϵͳ�������� " 
                            HIY + new_mail_n + HIG " �����ʼ����뵽�ʼ����Ĳ��ģ�\n" NOR);
	CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s(%s)��%s�������߽��롣", user->query("name"),
			user->query("id"), query_ip_number(user)));
}

int check_legal_id(string id)
{
	int i;

        if (id == "all")
        {
                write(WHT "\n�Բ���[" HIC "all" NOR + WHT "]�����������"
                      "��ĺ��⣬��������Ӣ�����֡�\n" NOR);
                return 0;
        }

	i = strlen(id);

	if ((strlen(id) < 3) || (strlen(id) > 10))
	{
		write(WHT "\n�Բ������Ӣ�����ֱ�����" HIY " 3 " NOR +
                      WHT "��" HIY " 10 " NOR + WHT "��Ӣ����ĸ��\n" NOR);
		return 0;
	}

	while (i--)
        {
		if (id[i] < 'a' || id[i] > 'z' )
		{
			write(WHT "\n�Բ������Ӣ������ֻ����Ӣ����ĸ��\n" NOR);
			return 0;
		}
        }

	return 1;
}

int check_legal_name(string name, int maxlen)
{
	int i;

	i = strlen(name);

	if (! is_chinese(name))
	{
		write(WHT "�Բ��������á�" HIY "����" NOR + WHT
                      "��ȡ���֡�\n" NOR);
		return 0;
	}
	
	if ((strlen(name) < 2) || (strlen(name) > maxlen))
	{
		write(WHT "�Բ������������������̫����\n" NOR);
		return 0;
	}

	if (member_array(name, banned_name) % 2 == 0)
	{
		write(WHT "�Բ���������������������˵����š�\n" NOR);
		return 0;
	}

	return 1;
}

object find_body(string name)
{
	return find_player(name);
}

int set_wizlock(int level)
{
	if (wiz_level(this_player(1)) <= level)
		return 0;

	if (geteuid(previous_object()) != ROOT_UID)
		return 0;

	wiz_lock_level = level;
	return 1;
}

int can_login(int level)
{
        if (level < wiz_lock_level)
                return 0;

        return 1;
}

int howmuch_money(object ob)
{
	int total;
	int total2;
	object gold, silver, coin;

	total = 0;
	total2 = 0;

	gold = present("gold_money",ob);
	silver = present("silver_money",ob);
	coin = present("coin_money",ob);

	if( gold ) total += gold->value();
	if( silver ) total += silver->value();
	if( coin ) total += coin->value();

	total2 = (int)ob->query("balance");
	if (!total2 || total2 < 0) {
		ob->set("balance", 0);
	}
	total=total+total2;
	return total;
}
